//
// Created by kkyse on 10/3/2017.
//

#include "string_tests.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#include "util.h"

#define set_type(return_t) const char *type = "%"#return_t

#define test(func, return_t) static inline Result *test_str##func(func(), Result *results) { \
    set_type(return_t); \
    results->result = RARE_SIZE; \
    results->type = "str"#func; \
    results++;

#define add_result(result_val) \
    results->result = (size_t) (result_val); \
    results->type = type; \
    results++

#define end_test() return results;}

#define run_test(name) \
    printf("\tTesting str"#name"\n"); \
    results = test_str##name(funcs.str##name, results)

typedef struct typed_result_t {
    size_t result;
    const char *type;
} Result;

typedef struct results_t {
    Result results[NUM_TESTS];
    uint num_results;
} Results;

static const size_t RARE_SIZE = (size_t) -1000; // I'm trying to choose a number that will rarely be returned.

test(len, zu)
    add_result(strlen("hello"));
    add_result(strlen("My name is Khyber Sen"));
    const char *const s = rand_string(rand_size(RAND_SIZE));
    add_result(strlen(s));
    free((char *) s);
end_test()

test(nlen, zu)
//    const size_t size = rand_size(RAND_SIZE);
//    size_t n = RAND_SIZE / 2;
//    if (n > size) {
//        n = size;
//    }
//    const char *const s = rand_string(size);
//    add_result(strnlen(s, n));
//    free((char *) s);
    add_result(0);
end_test()

test(cpy, p)
    add_result(0);
end_test()

test(ncpy, p)
    add_result(0);
end_test()

test(cat, p)
    add_result(0);
end_test()

test(ncat, p)
    add_result(0);
end_test()

test(cmp, d)
    add_result(strcmp("Hello, Khyber", "Hello, Jawad"));
    add_result(strcmp("Hello, Jawad", "Hello, Khyber"));
end_test()

test(ncmp, d)
    add_result(0);
end_test()

test(chr, p)
    add_result(strchr("Hello, World", ','));
end_test()

test(str, p)
    add_result(0);
end_test()

Result *test_string_funcs(const StringFuncs *const funcs_ptr, Result *results) {
    const StringFuncs funcs = *funcs_ptr;
    printf("Testing %s's Implementation of String Functions:\n", funcs.name);
    
    run_test(len);
    run_test(nlen);
    run_test(cpy);
    run_test(ncpy);
    run_test(cat);
    run_test(ncat);
    run_test(cmp);
    run_test(ncmp);
    run_test(chr);
    run_test(str);
    
    printf("\n");
    return results;
}

Results *run_all_string_funcs(const StringFuncs *const all_string_funcs, const uint num_string_funcs) {
    printf("run_all_string_funcs started\n");
    Results *const all_results = (Results *) calloc(0, num_string_funcs * sizeof(Results));
    const uint seed = (uint) time(NULL);
    for (uint i = 0; i < num_string_funcs; ++i) {
        Results *const results = all_results + i;
        Result *const inner_results = results->results;
        srand(seed); // need same seed
        results->num_results = (uint) (test_string_funcs(all_string_funcs + i, inner_results) - inner_results);
    }
    printf("run_all_string_funcs finished\n");
    return all_results;
}

int compare_result(const Result *const baseline, const Result *const test) {
    printf("compare_result started\n");
    if (test->result == RARE_SIZE) {
        printf("\t%s's results:\n", test->type);
        return 0;
    }
    bool correct = baseline->result == test->result;
    char *const format = (char *) malloc(100 * sizeof(char));
    
    getc(stdin);
    printf("unpacking types\n");
    const char *const baseline_type = baseline->type;
    const char *const test_type = test->type;
    printf("sprintf started\n");
    sprintf(format, "\t\t%s %s %s%s\n",
            baseline_type,
            correct ? "==" : "!=",
            test_type,
            correct ? "" : "\t\t(FAILED)"
    );
    printf("sprintf finished\n");
    getc(stdin);
    
    printf(format);
    printf(format, baseline->result, test->result);
    free(format);
    printf("compare_result finished\n");
    return correct ? 0 : 1;
}

void compare_all_string_funcs(const StringFuncs *const all_string_funcs, const uint num_string_funcs,
                              const uint baseline_index) {
    assert(baseline_index < num_string_funcs);
    
    Results *const all_results = run_all_string_funcs(all_string_funcs, num_string_funcs);
    
    const char *const baseline_name = all_string_funcs[baseline_index].name;
    const Results *const baseline_results_obj = all_results + baseline_index;
    const uint num_results = baseline_results_obj->num_results;
    const Result *const baseline_results = baseline_results_obj->results;
    for (uint i = 0; i < num_string_funcs; ++i) {
        const char *const name = all_string_funcs[i].name;
        const Result *const test_results = all_results[i].results;
        printf("%s's Results Compared to the Baseline (%s) Results:\n", name, baseline_name);
        uint num_wrong = 0;
        for (uint j = 0; j < num_results; ++j) {
            num_wrong += compare_result(baseline_results + j, test_results + j);
        }
        printf("%s's implementation failed %u tests\n\n", name, num_wrong);
    }
    free(all_results);
    printf("compare_all_string_funcs done");
}

void compare_string_funcs(const StringFuncs *const baseline_string_funcs, const StringFuncs *const test_string_funcs) {
    const StringFuncs all_string_funcs[] = {*baseline_string_funcs, *test_string_funcs};
    compare_all_string_funcs(all_string_funcs, arraysize(all_string_funcs), 0);
    printf("compare_string_funcs done");
}