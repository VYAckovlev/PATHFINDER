#include "../inc/pathfinder.h"

void show_error(ErrorType err_code, const char *file, int line_num) {
    switch (err_code) {
        case ERR_USAGE:
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
        case ERR_FILE_NOT_FOUND:
            mx_printerr("error: file ");
            mx_printerr(file);
            mx_printerr(" does not exist\n");
            break;
        case ERR_FILE_EMPTY:
            mx_printerr("error: file ");
            mx_printerr(file);
            mx_printerr(" is empty\n");
            break;
        case ERR_INVALID_LINE:
            mx_printerr("error: line ");
            mx_printint(line_num);
            mx_printerr(" is not valid\n");
            break;
        case ERR_INVALID_ISLAND_COUNT:
            mx_printerr("error: invalid number of islands\n");
            break;
        case ERR_DUPLICATE_BRIDGES:
            mx_printerr("error: duplicate bridges\n");
            break;
        case ERR_BRIDGE_SUM_OVERFLOW:
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;
        default:
            mx_printerr("error: unknown error\n");
            break;
    }
}



