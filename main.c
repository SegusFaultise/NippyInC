#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

#include "include/parse_nip_files.h"
#include "include/tokenizer.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../TextFiles/sonnets.txt"
#define TEST3_FILE_PATH "../TextFiles/98M.txt"
#define TEST4_FILE_PATH "../TextFiles/gen.c"


int main(int argc, char **argv) {
    printf("Running: %s\n", argv[0]);

    char *file_contents = read_in_nip_file(TEST_FILE_PATH);
    size_t file_size = get_file_size(TEST_FILE_PATH);

    //printf("[PARSED NIP FILE] %s\n", file_contents);

    build_token_stream(file_contents, file_size, DEBUG_ON);

    return 0;
}
