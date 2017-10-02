

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool m_strcmp(const char *s1, const char *s2) {
    char c1;
    char c2;
    while ((c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

bool m_strncmp(const char *s1, const char *s2, size_t length) {
    char c1;
    char c2;
    while (length-- && (c1 = *s1++) && (c2 = *s2++) && c1 == c2);
    return c1 - c2;
}

const char *m_strchr(const char *s, const int c) {
    if (c == 0) {
        return s + m_strlen(s);
    }
    char temp;
    while ((temp = *s++) && temp != c);
    if (temp == c) {
        return s - 1;
    }
    return NULL;
}

const char *m_strstr(const char *s1, const char *s2) {
    for (int i = 0; s1[i]; s1++) {
        
    }
}

int my_strlen(char *s) {
    return (int) m_strlen(s);
}

int my_strnlen(char *s, int n) {
    return (int) m_strnlen(s, (size_t) n);
}

char *my_strcpy(char *dest, char *source) {
    return m_strcpy(dest, source);
}

char *my_strncpy(char *dest, char *source, int n) {
    return m_strncpy(dest, source, (size_t) n);
}

char *my_strcat(char *dest, char *source) {
    return m_strcat(dest, source);
}

char *my_strncat(char *dest, char *source, int n) {
    return m_strncat(dest, source, (size_t) n);
}

int my_strcmp(char *s1, char *s2) {
    return m_strcmp(s1, s2);
}

char *my_strchr(char *s1, char c) {
    return (char *) m_strchr(s1, c);
}

char *my_strstr(char *s1, char *s2) {
    return (char *) m_strstr(s1, s2);
}

int main() {
    printf("%zu\n", m_strlen("Hello"));
    printf("%zu\n", m_strnlen("Hello", 3));
    printf("%zu\n", m_strnlen("Hello", 10));
    
    char *s = (char *) malloc(1000);
    m_strcpy(s, "Hello");
    printf("%s\n", s);
    
    m_strncpy(s, "Hello, World", 6);
    printf("%s\n", s);
    
    m_strncpy(s, "Hello, World", 20);
    printf("%s\n", s);
    
}