#include <../inc/libmx.h> 

void *mx_memrcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[n - 1 - i] = s[n - 1 - i];
    }

    return dst;
}


