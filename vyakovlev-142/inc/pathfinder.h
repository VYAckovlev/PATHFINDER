#ifndef PATHFINDER_H
#define PATHFINDER_H


#include "../libmx/inc/libmx.h"


typedef enum {
    ERR_USAGE,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_EMPTY,
    ERR_INVALID_LINE,
    ERR_INVALID_ISLAND_COUNT,
    ERR_DUPLICATE_BRIDGES,
    ERR_BRIDGE_SUM_OVERFLOW
} ErrorType;




typedef struct s_connection {
    struct s_location *target;
    int distance;
    struct s_connection *next;
} t_connection;


typedef struct s_location {
    int id;
    char *label;
    t_connection *links;
} t_location;


typedef struct s_network {
    t_location **nodes;
    int current_count;
    int capacity;
} t_network;


typedef struct s_min_heap {
    int *distances;
    int *ids;
    int current_size;
} t_min_heap;


void show_error(ErrorType err_code, const char *file, int line);
bool validate_bridge_format(const char *line);


void release_network(t_network *network);
void release_connections(t_connection *connection);
void release_location(t_location *location);


t_network *initialize_network(int capacity);
void resize_network(t_network *network);
t_location *register_location(t_network *network, char *label, int *id);
bool connect_locations(t_location *loc1, t_location *loc2, int distance);
t_network *parse_file(const char *file_name);


void display_path(t_network *network, int *path, int length, int end_id);
void locate_paths(t_network *network, int *distances, int curr, int end, int *path, int length);
void compute_dijkstra(t_network *network, int start, int *distances);
void display_route(t_network *network, int start, int end);
void show_all_routes(t_network *network);


t_min_heap *create_heap(int count);
int extract_min(t_min_heap *heap, int *visited);

#endif




