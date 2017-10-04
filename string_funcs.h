//
// Created by kkyse on 10/3/2017.
//

#ifndef SYSTEMS_STRING_FUNCS_H
#define SYSTEMS_STRING_FUNCS_H

#include <stdlib.h>

#define len() size_t (*const strlen)(const char *const s)
#define nlen() size_t (*const strnlen)(const char *const s, size_t length)
#define cpy() char *(*const strcpy)(char *dest, const char *src)
#define ncpy() char *(*const strncpy)(char *dest, const char *src, size_t length)
#define cat() char *(*const strcat)(char *dest, const char *src)
#define ncat() char *(*const strncat)(char *dest, const char *src, size_t length)
#define cmp() int (*const strcmp)(const char *s1, const char *s2)
#define ncmp() int (*const strncmp)(const char *s1, const char *s2, size_t length)
#define chr() char *(*const strchr)(const char *s, int c)
#define str() char *(*const strstr)(const char *s1, const char *s2)

typedef struct string_funcs_t {
    
    const char *const name;
    
    len();
    
    nlen();
    
    cpy();
    
    ncpy();
    
    cat();
    
    ncat();
    
    cmp();
    
    ncmp();
    
    chr();
    
    str();
    
} StringFuncs;

#define new_StringFuncs(name, prefix) { \
    name, \
    &prefix##len, \
    &prefix##nlen, \
    &prefix##cpy, \
    &prefix##ncpy, \
    &prefix##cat, \
    &prefix##ncat, \
    &prefix##cmp, \
    &prefix##ncmp, \
    &prefix##chr, \
    &prefix##str \
}

extern const StringFuncs MyStringFuncs;
extern const StringFuncs StdStringFuncs;

#endif //SYSTEMS_STRING_FUNCS_H
