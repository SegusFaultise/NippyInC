#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../sonnets.txt"

#define STRING_IGNORES "\t\n "
#define RAW_FILE_STRING_PAD 244

char *extract_alpha(char *token_stream, size_t *token_index, size_t *token_stream_length) {
    int start = *token_index;
    int alpha_length = 0;

    char *alpha = NULL;

    while(isalpha(token_stream[*token_index]) ||
          isalpha(token_stream[*token_index] || token_stream[*token_index] == '_')) {

        (*token_index)++;
        alpha_length++;
    }         

    if(alpha_length > 0) {
        alpha = malloc(alpha_length + 1);

        if(alpha == NULL) {
            free(alpha);

            return NULL;
        }

        memcpy(alpha, token_stream + start, alpha_length);
        alpha[alpha_length] = '\0'; 
        return alpha;
    }
    else {
        return NULL;
    }
}

void build_token_stream(char *raw_file_string, size_t raw_file_string_size) {
    size_t token_index = 0;

    if(raw_file_string == NULL || 
        token_index < 0 || 
        raw_file_string[token_index] == '\0') {

        fprintf(stderr, "Error: The giving [raw_file_string] is NULL!");
        exit(-1);
    }

    while(token_index < raw_file_string_size - 1) {
        if(ispunct(raw_file_string[token_index])) {
            printf("TOKEN_SYMBOL: %c\n", raw_file_string[token_index]);
        }
        if(isdigit(raw_file_string[token_index])) {
            printf("TOKEN_DIGIT: %c\n", raw_file_string[token_index]);
        }
        if(isalpha(raw_file_string[token_index])){
            printf("TOKEN_ALPHA: %s\n", extract_alpha(raw_file_string, &token_index, &raw_file_string_size));
        }
        else {
            token_index++;
        }
    }
    return;
}

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");

    struct FileData file_data;

    char *file_contents = read_in_nip_file(TEST_FILE_PATH, &file_data);
    size_t file_size = strnlen(file_contents, strlen(file_contents));

    //printf("[PARSED NIP FILE] %s\n", file_contents);

    build_token_stream(file_contents, file_size);

    return 0;
}
