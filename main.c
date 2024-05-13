#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../sonnets.txt"

#define STRING_IGNORES "\t\n "
#define RAW_FILE_STRING_PAD sizeof(uint64_t)

void build_token_stream(char *raw_file_string, size_t raw_file_string_size) {
    size_t token_index = 0;

    if(raw_file_string == NULL) {
        fprintf(stderr, "Error: The giving [raw_file_string] is NULL!");
        exit(-1);
    }

    while(token_index < raw_file_string_size) {
        if(isalpha(raw_file_string[token_index])) {
            printf("TOKEN_ALPHAS: %c\n", raw_file_string[token_index]);
        }
        else {
            printf("TOKEN_SYMBOLS: %c\n", raw_file_string[token_index]);
        }
        token_index++;
    }
}

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");

    struct FileData file_data;

    char *file_contents = read_in_nip_file(TEST_FILE_PATH, &file_data);
    size_t file_size = strnlen(file_contents, strlen(file_contents));

    printf("[PARSED NIP FILE] %s\n", file_contents);

    build_token_stream(file_contents, file_size);

    return 0;
}
