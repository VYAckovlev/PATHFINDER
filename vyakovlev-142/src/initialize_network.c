#include "../inc/pathfinder.h"

t_network *initialize_network(int capacity) {
    t_network *network = malloc(sizeof(t_network));
    network->current_count = 0;
    network->capacity = capacity;
    network->nodes = malloc(capacity * sizeof(t_location*));

    for (int i = 0; i < capacity; i++) {
        network->nodes[i] = NULL;
    }

    return network;
}





