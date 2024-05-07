#include <stdio.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");

    char *file_contents = read_in_nip_file(TEST_FILE_PATH);

    printf("%s", file_contents);
    

    return 0;
}
