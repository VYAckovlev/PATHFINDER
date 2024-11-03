#include "../inc/pathfinder.h"

void locate_paths(t_network *network, int *distances, int current, int end, int *path, int length) {
    path[length++] = current;

    if (current == end) {
        display_path(network, path, length, end);
        return;
    }

    t_connection *sorted_links[network->current_count];
    int neighbor_count = 0;

    for (t_connection *link = network->nodes[current]->links; link; link = link->next) {
        if (distances[link->target->id] == distances[current] + link->distance) {
            sorted_links[neighbor_count++] = link;
        }
    }

    for (int i = 0; i < neighbor_count - 1; i++) {
        for (int j = i + 1; j < neighbor_count; j++) {
            if (sorted_links[i]->target->id > sorted_links[j]->target->id) {
                t_connection *temp = sorted_links[i];
                sorted_links[i] = sorted_links[j];
                sorted_links[j] = temp;
            }
        }
    }

    for (int i = 0; i < neighbor_count; i++) {
        int neighbor = sorted_links[i]->target->id;

        bool is_in_path = false;
        for (int j = 0; j < length; j++) {
            if (path[j] == neighbor) {
                is_in_path = true;
                break;
            }
        }

        if (!is_in_path) {
            locate_paths(network, distances, neighbor, end, path, length);
        }
    }
}




