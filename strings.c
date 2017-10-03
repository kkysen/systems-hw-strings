

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

typedef struct typed_result_t {
    size_t result;
    const char *type;
} Result;

#define NUM_TESTS 100

#define test_header(func) Result *test_str##func(func(), Result *results)

#define add_result(result_val, type_val) \
    results->result = (size_t) (result_val); \
    results->type = (type_val); \
    results++

test_header(len) {
    add_result(strlen("hello"), "%zu");
    add_result(strlen("My name is Khyber Sen"), "%zu");
    return results;
}

test_header(nlen) {
    return results;
}

test_header(cpy) {
    return results;
}

test_header(ncpy) {
    return results;
}

test_header(cat) {
    return results;
}

test_header(ncat) {
    return results;
}

test_header(cmp) {
    add_result(strcmp("Hello, Khyber", "Hello, Jawad"), "%d");
    add_result(strcmp("Hello, Jawad", "Hello, Khyber"), "%d");
    return results;
}

test_header(ncmp) {
    return results;
}

test_header(chr) {
    add_result(strchr("Hello, World", ','), "%p");
    return results;
}

test_header(str) {
    return results;
}

#define test(name) \
    printf("\tTesting str"#name"\n"); \
    results = test_str##name(funcs.str##name, results); \
    printf("\n") \


Result *test_string_funcs(const StringFuncs *const funcs_ptr, Result *results) {
    const StringFuncs funcs = *funcs_ptr;
    printf("Testing %s Implementation of String Functions:\n\n", funcs.name);
    
    test(len);
    test(nlen);
    test(cpy);
    test(ncpy);
    test(cat);
    test(ncat);
    test(cmp);
    test(ncmp);
    test(chr);
    test(str);
    
    return results;
}

typedef struct results_t {
    Result results[NUM_TESTS];
    uint num_results;
} Results;

#define arraysize(array) (sizeof((array)) / sizeof(*(array)))

#define membersize(struct, member) (sizeof(((struct *)0)->member))

void compare_all_string_funcs(const StringFuncs *all_string_funcs, const uint num_string_funcs,
                              const uint baseline_string_funcs_index) {
    assert(baseline_string_funcs_index < num_string_funcs);
    Results *const all_results = (Results *) calloc(0, num_string_funcs * sizeof(Results));
    for (uint i = 0; i < num_string_funcs; ++i) {
        Results *const results = all_results + i;
        Result *const inner_results = results->results;
        results->num_results = (uint) (test_string_funcs(all_string_funcs + i, inner_results) - inner_results);
    }
    
    const char *const baseline_name = all_string_funcs[baseline_string_funcs_index].name;
    const Result *const baseline_results = all_results[baseline_string_funcs_index].results;
    for (uint i = 0; i < num_string_funcs; ++i) {
        const char *const name = all_string_funcs[i].name;
        const uint num_results = all_results[i].num_results;
        const Result *const test_results = all_results[i].results;
        printf("%s's Results Compared to the Baseline (%s) Results:\n", name, baseline_name);
        for (uint j = 0; j < num_results; ++j) {
            const Result *const baseline = baseline_results + j;
            const Result *const test = test_results + j;
            bool correct = baseline->result == test->result;
            char *const format = (char *) malloc(10 * sizeof(char));
            sprintf(format, "\t%s %s %s\n", baseline->type, correct ? "==" : "!=", test->type);
            printf(format, baseline->result, test->result);
        }
        printf("\n");
    }
}

void compare_string_funcs(const StringFuncs *const baseline_string_funcs, const StringFuncs *const test_string_funcs) {
    const StringFuncs all_string_funcs[] = {*baseline_string_funcs, *test_string_funcs};
    compare_all_string_funcs(all_string_funcs, arraysize(all_string_funcs), 0);
}

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

const StringFuncs mine = new_StringFuncs("Khyber and Jawad", m_str);
const StringFuncs std = new_StringFuncs("Std", str);

int main() {
    printf("\n");
    compare_string_funcs(&std, &mine);
    
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