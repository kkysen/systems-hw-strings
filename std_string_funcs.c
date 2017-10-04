//
// Created by kkyse on 10/3/2017.
//

#include "string_funcs.h"

#include <string.h>

size_t strnlen(const char *s, size_t n);

const StringFuncs StdStringFuncs = //new_StringFuncs("string.h", str);
        {
                "string.h",
                &strlen,
                &strnlen,
                &strcpy,
                &strncpy,
                &strcat,
                &strncat,
                &strcmp,
                &strncmp,
                &strchr,
                &strstr
        };