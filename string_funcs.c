//
// Created by kkyse on 10/4/2017.
//

#include "string_funcs.h"

size_t m_strlen(const char *const s) {
    const char *p = s - 1;
    while (*++p);
    return p - s;
}

size_t m_strnlen(const char *const s, size_t length) {
    const char *p = s - 1;
    length += 2;
    while (--length && *++p);
    return p - s;
}

char *m_strcpy(char *dest, const char *src) {
    char *tmp = dest;
    while ((*dest++ = *src++));
    return tmp;
}

char *m_strncpy(char *dest, const char *src, size_t length) {
    char *tmp = dest;
    while (length-- && (*dest++ = *src++));
    return tmp;
}

char *m_strcat(char *dest, const char *src) {
    char *tmp = dest;
    while (*dest++);
    while ((*dest++ = *src++));
    return tmp;
}

char *m_strncat(char *dest, const char *src, size_t length) {
    char *tmp = dest;
    while (*dest++);
    while (length-- && (*dest++ = *src++));
    return tmp;
}

int m_strcmp(const char *s1, const char *s2) {
    char c1;
    char c2;
    while ((c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

int m_strncmp(const char *s1, const char *s2, size_t length) {
    char c1;
    char c2;
    while (length-- && (c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

char *m_strchr(const char *s, const int c) {
    if (c == 0) {
        return (char *) s + m_strlen(s);
    }
    char temp;
    while ((temp = *s++) && temp != c);
    if (temp == c) {
        return (char *) s - 1;
    }
    return NULL;
}

char *m_strstr(const char *s1, const char *s2) {
    for (int i = 0; s1[i]; s1++) {
    
    }
    return (char *) s1; // FIXME
}