#include "../inc/pathfinder.h"

t_location *register_location(t_network *network, char *label, int *id) {
    for (int i = 0; i < network->current_count; i++) {
        if (mx_strcmp(network->nodes[i]->label, label) == 0) {
            return network->nodes[i];
        }
    }

    resize_network(network);

    t_location *new_location = malloc(sizeof(t_location));
    new_location->label = mx_strdup(label);
    new_location->links = NULL;
    new_location->id = *id;

    network->nodes[network->current_count] = new_location;
    (*id)++;
    network->current_count++;

    return new_location;
}





