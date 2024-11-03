#include "../inc/pathfinder.h"

void compute_dijkstra(t_network *network, int start, int *distances) {
    int count = network->current_count;
    int *visited = malloc(count * sizeof(int));
    if (visited == NULL) {
        exit(1); //  allocation failure
    }
    mx_memset(visited, 0, count * sizeof(int)); //memset new array to all zeroes

    t_min_heap *heap = create_heap(count);

    for (int i = 0; i < count; i++) {
        distances[i] = INT_MAX;
    }

    distances[start] = 0;
    heap->distances[start] = 0;

    for (int i = 0; i < count; i++) {
        int current = extract_min(heap, visited);

        if (current == -1) {
            break;
        }

        visited[current] = 1;

        for (t_connection *conn = network->nodes[current]->links; conn != NULL; conn = conn->next) {
            int neighbor = conn->target->id;
            int new_distance = distances[current] + conn->distance;

            if (!visited[neighbor] && new_distance < distances[neighbor]) {
                distances[neighbor] = new_distance;
                heap->distances[neighbor] = new_distance;
            }
        }
    }

    free(heap->distances);
    free(heap->ids);
    free(heap);
    free(visited);
}



