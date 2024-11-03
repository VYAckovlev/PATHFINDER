#include "../inc/pathfinder.h"

bool connect_locations(t_location *loc1, t_location *loc2, int distance) {
    t_connection *conn = loc1->links;
    
    while (conn != NULL) {
        if (conn->target == loc2) {
            return true;
        }
        conn = conn->next;
    }

    conn = loc2->links;

    while (conn != NULL) {
        if (conn->target == loc1) {
            return true;
        }
        conn = conn->next;
    }

    t_connection *new_conn1 = malloc(sizeof(t_connection));
    new_conn1->target = loc2;
    new_conn1->distance = distance;
    new_conn1->next = loc1->links;
    loc1->links = new_conn1;

    t_connection *new_conn2 = malloc(sizeof(t_connection));
    new_conn2->target = loc1;
    new_conn2->distance = distance;
    new_conn2->next = loc2->links;
    loc2->links = new_conn2;

    return false;
}




