#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size == 0 || !lineptr) {
        return -2;
    }

    ssize_t bytes_read = 0;
    size_t total_size = 0;
    bool found_delim = false;
    char ch;
    char *str = (char *)malloc(buf_size);

    if (!str) {
        return -2;
    }

    while ((bytes_read = read(fd, &ch, 1)) > 0) {
        if (ch == '\r') {  // Skipreturns
            continue;
        }
        if (ch == delim) {  // Stop when there is a delim
            found_delim = true;
            break;
        }

        if (total_size + 1 >= buf_size) {  // Resize buffer(opt)
            buf_size *= 2;
            char *new_str = mx_realloc(str, buf_size);
            if (!new_str) {
                free(str);
                return -2;
            }
            str = new_str;
        }

        str[total_size++] = ch;  // Add character to string
    }

    if (bytes_read == 0 && total_size == 0) {  // file end
        free(str);
        return -1;
    }

    str[total_size] = '\0';  // Nullterminate str
    *lineptr = str;

    return found_delim ? total_size : 0;  //length if delim found, other 0
}

