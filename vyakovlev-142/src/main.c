#include "../inc/pathfinder.h"
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        show_error(ERR_USAGE, NULL, 0);
        return 1;
    }

    t_network *network = parse_file(argv[1]);

    show_all_routes(network);
    release_network(network);
    return 0;
}





