#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../sonnets.txt"
#define TEST3_FILE_PATH "../98M.txt"
#define TEST4_FILE_PATH "../gen.c"

#define STRING_IGNORES "\t\n "
#define RAW_FILE_STRING_PAD 244

#define IS_CHILD_PROCESS 0

#define DEBUG_STATMENT printf("DEBUG_IS_HERE\n");

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
        alpha = malloc(alpha_length + sizeof *token_index);

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

void build_token_stream_threads(char *raw_file_string, size_t raw_file_string_size) {
    size_t token_index = 0;
    pid_t p_fork = fork();


    if(raw_file_string == NULL || 
            token_index < 0 || 
            raw_file_string[token_index] == '\0') {

        fprintf(stderr, "Error: The giving [raw_file_string] is NULL!");
        exit(-1);
    }
    if(p_fork<0) {
        fprintf(stderr, "Error: fork() failed!");
        exit(1);
    }
    else if(p_fork == IS_CHILD_PROCESS)
    while(token_index < raw_file_string_size - 1) {
        if(token_index > raw_file_string_size) break;

        if(ispunct(raw_file_string[token_index])) {
            //printf("TOKEN_SYMBOL: %c\n", raw_file_string[token_index]);
        }
        if(isdigit(raw_file_string[token_index])) {
            //printf("TOKEN_DIGIT: %c\n", raw_file_string[token_index]);
        }
        if(isalpha(raw_file_string[token_index])){
            //printf("TOKEN_ALPHA: %s\n", extract_alpha(raw_file_string, &token_index, &raw_file_string_size));
            extract_alpha(raw_file_string, &token_index, &raw_file_string_size);
        }
        else {
            token_index++;
        }
    }
    return;
}

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");


    char *file_contents = read_in_nip_file(TEST2_FILE_PATH);
    size_t file_size = get_file_size(TEST2_FILE_PATH);

    //printf("[PARSED NIP FILE] %s\n", file_contents);

    build_token_stream_threads(file_contents, file_size);

    return 0;
}
