#include "../inc/pathfinder.h"

void display_route(t_network *network, int start, int end) {
    int *distances = malloc(network->current_count * sizeof(int));
    int *path = malloc(network->current_count * sizeof(int));

    compute_dijkstra(network, start, distances);
    locate_paths(network, distances, start, end, path, 0);

    free(distances);
    free(path);
}

