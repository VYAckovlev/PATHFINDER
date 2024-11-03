#include "../inc/pathfinder.h"

t_network *parse_file(const char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        show_error(ERR_FILE_NOT_FOUND, file_name, 0);
        exit(1);
    }

    char *line = NULL;
    int island_count = 0;
    int location_id = 0;
    t_network *network = NULL;
    long total_bridge_length = 0;
    bool has_duplicates = false;
    int result = mx_read_line(&line, 1, '\n', fd);

    if (result == -1) {
        close(fd);
        show_error(ERR_FILE_EMPTY, file_name, 0);
        exit(1);
    }

    if (result > 0) {
        island_count = mx_atoi(line);
        if (island_count <= 0 || !mx_isnumber(line)) {
            mx_strdel(&line);
            close(fd);
            show_error(ERR_INVALID_LINE, NULL, 1);
            exit(1);
        } else {
            network = initialize_network(island_count);
            mx_strdel(&line);
        }
    } else {
        mx_strdel(&line);
        close(fd);
        show_error(ERR_INVALID_LINE, NULL, 1);
        exit(1);
    }

    int line_num = 2;
    result = 0;

    while ((result = mx_read_line(&line, 1, '\n', fd)) != -1) {
        if (result == -3 || result == 0 || (line && *line == '\0')) {
            mx_strdel(&line);
            release_network(network);
            close(fd);
            show_error(ERR_INVALID_LINE, NULL, line_num);
            exit(1);
        }

        if (!validate_bridge_format(line)) {
            mx_strdel(&line);
            release_network(network);
            close(fd);
            show_error(ERR_INVALID_LINE, NULL, line_num);
            exit(1);
        }

        char **parts = mx_strsplit(line, ',');
        char **locations = mx_strsplit(parts[0], '-');

        t_location *loc1 = register_location(network, locations[0], &location_id);
        t_location *loc2 = register_location(network, locations[1], &location_id);

        int distance = atoi(parts[1]);
        if (connect_locations(loc1, loc2, distance)) {
            has_duplicates = true;
        }
        total_bridge_length += distance;

        mx_del_strarr(&parts);
        mx_del_strarr(&locations);
        mx_strdel(&line);

        line_num++;
    }

    if (network->current_count != island_count) {
        release_network(network);
        show_error(ERR_INVALID_ISLAND_COUNT, NULL, 0);
        exit(1);
    }

    if (has_duplicates) {
        release_network(network);
        show_error(ERR_DUPLICATE_BRIDGES, NULL, 0);
        exit(1);
    }

    if (total_bridge_length > INT_MAX) {
        release_network(network);
        show_error(ERR_BRIDGE_SUM_OVERFLOW, NULL, 0);
        exit(1);
    }

    close(fd);
    return network;
}



