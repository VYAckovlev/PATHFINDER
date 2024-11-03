#include "../inc/pathfinder.h"

void resize_network(t_network *network) {
    if (network->current_count >= network->capacity) {
        network->capacity *= 2;
        network->nodes = realloc(network->nodes, network->capacity * sizeof(t_location*));

        if (!network->nodes) {
            exit(1);  // realloc failure 
        }

        for (int i = network->current_count; i < network->capacity; i++) {
            network->nodes[i] = NULL;
        }
    }
}




