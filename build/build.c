#include <stdio.h>

#include "../lib/FKN-Build/include/FKN_build.h"

#define EXE_NAME "Nippy"

struct BuildFiles build_files[] = {
    {.file_path = "../src/parse_nip_files.c"},
    {.file_path = "../main.c"},
};

void build_nippy() {
    size_t build_file_array = FKN_GET_ARRAY_LENGTH(build_files);

    FKN_BUILD(build_files, build_file_array, EXE_NAME);
}

int main() {
    build_nippy();
}
