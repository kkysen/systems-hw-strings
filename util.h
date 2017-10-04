//
// Created by kkyse on 10/3/2017.
//

#ifndef SYSTEMS_UTIL_H
#define SYSTEMS_UTIL_H

#include <stdlib.h>
#include <stdio.h>

#define arraysize(array) (sizeof((array)) / sizeof(*(array)))

#define membersize(struct, member) (sizeof(((struct *)0)->member))

#define div_ceil(a, b) ((a) / (b) + ((a) % (b) != 0))

char *rand_string(size_t length) {
    char *s = (char *) malloc(length * sizeof(char));
    while (length-- > 0) {
        s[length] = (char) rand();
    }
    s[length - 1] = 0;
    return s;
}

#define rand_size(max) ((size_t) (rand() % (max)))

#endif //SYSTEMS_UTIL_H
