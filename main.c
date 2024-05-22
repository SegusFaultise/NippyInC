#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

#include "include/parse_nip_files.h"
#include "include/tokenizer.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../sonnets.txt"
#define TEST3_FILE_PATH "../98M.txt"
#define TEST4_FILE_PATH "../gen.c"
#define TEST5_FILE_PATH "../ll.txt"

#define DEBUG_STATMENT printf("DEBUG_IS_HERE\n");

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");


    char *file_contents = read_in_nip_file(TEST5_FILE_PATH);
    size_t file_size = get_file_size(TEST5_FILE_PATH);

    //printf("[PARSED NIP FILE] %s\n", file_contents);

    build_token_stream(file_contents, file_size, DEBUG_ON);

    return 0;
}
