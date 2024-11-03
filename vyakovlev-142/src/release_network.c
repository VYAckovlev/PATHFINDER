#include "../inc/pathfinder.h"

void release_network(t_network *network) {
    if (network) {
        for (int i = 0; i < network->current_count; i++) {
            release_location(network->nodes[i]);
        }
        
        free(network->nodes);
        free(network);
    }
}






