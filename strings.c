//
// Created by kkyse on 10/2/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "string_tests.h"


int main() {
    printf("\n");
    compare_string_funcs(&StdStringFuncs, &MyStringFuncs);
    printf("done\n");
    return 0;
}

/*
 * These functions implement DW's headers
 * by simply wrapping the above m_ prefixed functions,
 * which implement the same headers in string.h.
 */

#define my MyStringFuncs

int my_strlen(char *s) {
    return (int) my.strlen(s);
}

int my_strnlen(char *s, int n) {
    return (int) my.strnlen(s, (size_t) n);
}

char *my_strcpy(char *dest, char *source) {
    return my.strcpy(dest, source);
}

char *my_strncpy(char *dest, char *source, int n) {
    return my.strncpy(dest, source, (size_t) n);
}

char *my_strcat(char *dest, char *source) {
    return my.strcat(dest, source);
}

char *my_strncat(char *dest, char *source, int n) {
    return my.strncat(dest, source, (size_t) n);
}

int my_strcmp(char *s1, char *s2) {
    return my.strcmp(s1, s2);
}

char *my_strchr(char *s1, char c) {
    return (char *) my.strchr(s1, c);
}

char *my_strstr(char *s1, char *s2) {
    return (char *) my.strstr(s1, s2);
}

#undef my