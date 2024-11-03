#include "../inc/libmx.h"

void mx_swap_string(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int mx_partition(char **arr, int left, int right, int *res) {
    char *pivot = arr[right]; // Last elem is pivot
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (mx_strlen(arr[j]) < mx_strlen(pivot)) {
            i++;
            if (i != j) {
                mx_swap_string(&arr[i], &arr[j]);
                (*res)++;
            }
        }
    }

    if (mx_strlen(arr[i + 1]) != mx_strlen(arr[right])) {
        mx_swap_string(&arr[i + 1], &arr[right]);
        (*res)++;
    }
    return i + 1;
}

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) {
        return -1;
    }
    int res = 0;
    if (left < right) {
        int part_index = mx_partition(arr, left, right, &res);
        res += mx_quicksort(arr, left, part_index - 1);
        res += mx_quicksort(arr, part_index + 1, right);
    }
    return res;
}



