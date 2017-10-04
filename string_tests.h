//
// Created by kkyse on 10/3/2017.
//

#ifndef SYSTEMS_STRING_TESTS_H
#define SYSTEMS_STRING_TESTS_H

typedef unsigned int uint;

#include "string_funcs.h"

#define NUM_TESTS 100

#define RAND_SIZE 1000

void compare_all_string_funcs(const StringFuncs *all_string_funcs, const uint num_string_funcs,
                              const uint baseline_index);

void compare_string_funcs(const StringFuncs *const baseline_string_funcs, const StringFuncs *const test_string_funcs);

#endif //SYSTEMS_STRING_TESTS_H
