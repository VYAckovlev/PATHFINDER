#include "../inc/pathfinder.h"

t_min_heap *create_heap(int count) {
    t_min_heap *heap = malloc(sizeof(t_min_heap));
    heap->distances = malloc(count * sizeof(int));
    heap->ids = malloc(count * sizeof(int));
    heap->current_size = count;

    for (int i = 0; i < count; i++) {
        heap->distances[i] = INT_MAX;
        heap->ids[i] = i;
    }

    return heap;
}

