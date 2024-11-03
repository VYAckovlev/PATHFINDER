#include "../inc/pathfinder.h"

void release_location(t_location *location) {
    if (location) {
        release_connections(location->links);
        free(location->label);
        free(location);
    }
}




