#include "../inc/pathfinder.h"

void display_path(t_network *network, int *path, int length, int end) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(network->nodes[path[0]]->label);
    mx_printstr(" -> ");
    mx_printstr(network->nodes[end]->label);
    mx_printstr("\n");

    mx_printstr("Route: ");
    
    for (int i = 0; i < length; i++) {
        mx_printstr(network->nodes[path[i]]->label);
        (i != length - 1) ? mx_printstr(" -> ") : (void)0;
    }

    mx_printstr("\n");
    mx_printstr("Distance: ");

    int total_distance = 0;

    for (int i = 0; i < length - 1; i++) {
        int segment_distance = 0;
        t_connection *conn = network->nodes[path[i]]->links;

        while (conn) {
            if (conn->target->id == path[i + 1]) {
                segment_distance = conn->distance;
                total_distance += segment_distance;

                mx_printint(segment_distance);
                (i != length - 2) ? mx_printstr(" + ") : (void)0;

                break;
            }
            conn = conn->next;
        }
    }

    (length > 2) ? (mx_printstr(" = "), mx_printint(total_distance), mx_printstr("\n")) : mx_printstr("\n");

    mx_printstr("========================================\n");
}



