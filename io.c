//
// Created by kkyse on 10/5/2017.
//

#include "io.h"

#include <stdlib.h>
#include <string.h>

#define SAFE_IO_MODS true

const char *HOME = NULL;
size_t HOME_LEN = 0;

const char *get_home() {
    if (HOME == NULL) {
        HOME = getenv("HOME");
        HOME_LEN = strlen(HOME);
    }
    return HOME;
}

const size_t get_home_len() {
    get_home();
    return HOME_LEN;
}

bool is_sudo() {
    return system("sudo -v") == 0;
}

static inline bool contains(const char *const string, const char *const substring) {
    return strstr(string, substring) != NULL;
}

bool dangerous_filename(const char *const filename) {
    return contains(filename, "khyber")
           || contains(filename, "sen")
           || contains(filename, "kkyse")
           || is_sudo();
}

char *checked_filename(const char *const filename) {
    if (!dangerous_filename(filename)) {
        return (char *) filename;
    }
    #if (SAFE_IO_MODS)
    return NULL;
    #endif
    const size_t len = strlen(filename);
    char *const new_filename = (char *) malloc((len + 2) * sizeof(char)); // for ~ and null
    strcpy(new_filename, filename);
    new_filename[len] = '~';
    new_filename[len + 1] = 0;
    return new_filename;
}

//int modify_file(const char *const filename, int (*const modifier)(const FILE *const file)) {
//    return 0; // TODO
//}
