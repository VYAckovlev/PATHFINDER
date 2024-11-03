#include "../inc/pathfinder.h"

void release_connections(t_connection *conn) {
    while (conn) {
        t_connection *temp = conn;
        conn = conn->next;
        free(temp);
    }
}





