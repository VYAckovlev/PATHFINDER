#include "../inc/pathfinder.h"

int extract_min(t_min_heap *heap, int *visited) {
    int min_distance = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < heap->current_size; i++) {
        int index = heap->ids[i];
        
        if (!visited[index] && heap->distances[index] < min_distance) {
            min_distance = heap->distances[index];
            min_index = index;
        }
    }

    return min_index;
}



