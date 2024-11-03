#include "../inc/pathfinder.h"

void show_all_routes(t_network *network) {
    int count = network->current_count;

    for (int start = 0; start < count; start++) {
        for (int end = start + 1; end < count; end++) {
            display_route(network, start, end);
        }
    }
}





