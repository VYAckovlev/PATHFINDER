#include <../inc/libmx.h> 

int mx_isalpha(int c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;  
    }
    
    return 0;  
}
