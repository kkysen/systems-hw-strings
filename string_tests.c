//
// Created by kkyse on 10/4/2017.
//

#include "string_tests.h"

#include <stdio.h>

#include "string_funcs.h"

int main() {
    printf("test\n");
    
    //my_strlen
    printf("\"Hello\" has %zu characters.\n", my_strlen("Hello"));
    printf("\"\" has %zu characters.\n", my_strlen(""));
    
    //my_strnlen
    printf("\"Hello\" has %zu characters up to 5.\n", my_strnlen("Hello", 5));
    printf("\"Hello\" has %zu characters up to 6.\n", my_strnlen("Hello", 6));
    printf("\"Hello\" has %zu characters up to 70000.\n", my_strnlen("Hello", 70000));
    printf("\"Hello\" has %zu characters up to 4 characters.\n", my_strnlen("Hello", 4));
    printf("\"\" has %zu characters up to 1.\n", my_strnlen("", 1));
    
    //my_strcpy
    printf("TODO");
    
    return 0;
}