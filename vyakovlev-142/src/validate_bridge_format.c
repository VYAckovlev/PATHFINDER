#include "../inc/pathfinder.h"

bool validate_bridge_format(const char *line) {
    if (!line || mx_strlen(line) < 5) {
        return false;
    }

    const char *comma_pos = mx_strchr(line, ',');
    const char *dash_pos = mx_strchr(line, '-');

    if (!comma_pos || !dash_pos || dash_pos >= comma_pos || comma_pos - dash_pos <= 1 || *(comma_pos + 1) == '\0') {
        return false;
    }

    if (dash_pos == line || dash_pos + 1 == comma_pos) {
        return false;
    }

    size_t loc1_len = dash_pos - line;
    size_t loc2_len = comma_pos - dash_pos - 1;

    if (loc1_len == loc2_len && mx_strncmp(line, dash_pos + 1, loc1_len) == 0) {
        return false;
    }

    // Validate characters before and after the dash - alphabetic
    for (const char *p = line; p < dash_pos; ++p) {
        if (!mx_isalpha(*p)) {
            return false;
        }
    }
    for (const char *p = dash_pos + 1; p < comma_pos; ++p) {
        if (!mx_isalpha(*p)) {
            return false;
        }
    }

    // Validate characters after the comma -  numeric
    for (const char *p = comma_pos + 1; *p != '\0'; ++p) {
        if (!mx_isdigit(*p)) {
            return false;
        }
    }

    int distance = mx_atoi(comma_pos + 1);
    if (distance <= 0) {
        return false;
    }

    return true;
}

