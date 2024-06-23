#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include "../include/tokenizer.h"

#define STRING_IGNORES "\t\n\r "

enum TokenTypes {
    DIGIT_TOKEN,
    SYMBOL_TOKEN,
    ALPHA_TOKEN
};

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

void get_tokenizer_stats(size_t alpha_token_count, size_t digit_token_count, size_t symbol_token_count, char *token_array) {
    if(alpha_token_count < 0 || digit_token_count < 0 || symbol_token_count < 0) { 
        fprintf(stderr, "Error: token_index out of bounds"); 
        exit(1);
    }

    fprintf(stdout, "\n[NUMBER_OF_ALPHA_TOKENS]:\t (%ld)\n", alpha_token_count);
    fprintf(stdout, "[NUMBER_OF_DIGIT_TOKENS]:\t (%ld)\n", digit_token_count);
    fprintf(stdout, "[NUMBER_OF_SYMBOL_TOKENS]:\t (%ld)\n", symbol_token_count);
}

void build_token_stream(char *raw_file_string, size_t raw_file_string_size, enum TokenDebug token_debug_arg) {
    size_t token_index = 0;
    size_t alpha_token_count = 0;
    size_t symbol_token_count = 0;
    size_t digit_token_count = 0;

    if(raw_file_string == NULL || 
            token_index < 0 || 
            raw_file_string[token_index] == '\0') {

        fprintf(stderr, "Error: The giving [raw_file_string] is NULL!");
        exit(1);
    }

    while(token_index < raw_file_string_size - 1) {
        if(token_index > raw_file_string_size) break;

        if(ispunct(raw_file_string[token_index])) {
            symbol_token_count++;

            printf("%c\n", raw_file_string[token_index]);
        }
        if(isdigit(raw_file_string[token_index])) {
            digit_token_count++;

            printf("%d\n", atoi(&raw_file_string[token_index]));
        }
        if(isalpha(raw_file_string[token_index])) {
            char *extracted_alpha = extract_alpha(raw_file_string, &token_index, &raw_file_string_size); 

            alpha_token_count++;

            printf("%s\n", extracted_alpha);
        }
        token_index++;
    }

    if(token_debug_arg == DEBUG_OFF) printf("[DEBUG]: disabled");
    if(token_debug_arg == DEBUG_ON) get_tokenizer_stats(alpha_token_count, digit_token_count, symbol_token_count, raw_file_string);

    else return;
}
