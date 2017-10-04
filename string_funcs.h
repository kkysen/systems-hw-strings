//
// Created by kkyse on 10/4/2017.
//

#ifndef STRINGS_STRING_FUNCS_H
#define STRINGS_STRING_FUNCS_H

#include <stdlib.h>

size_t m_strlen(const char *const s);

size_t m_strnlen(const char *const s, size_t length);

char *m_strcpy(char *dest, const char *src);

char *m_strncpy(char *dest, const char *src, size_t length);

char *m_strcat(char *dest, const char *src);

char *m_strncat(char *dest, const char *src, size_t length);

int m_strcmp(const char *s1, const char *s2);

int m_strncmp(const char *s1, const char *s2, size_t length);

char *m_strchr(const char *s, const int c);

char *m_strstr(const char *s1, const char *s2) ;

#endif //STRINGS_STRING_FUNCS_H
