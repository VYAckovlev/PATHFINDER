#include <../inc/libmx.h> 

bool mx_isnumber(const char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }

    if (str[0] == '0' && str[1] != '\0') {
        return false;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isdigit((unsigned char)str[i])) {
            return false;
        }
    }
    
    return true; 
}
