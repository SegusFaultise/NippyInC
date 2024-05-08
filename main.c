#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"
#define TEST2_FILE_PATH "../sonnets.txt"

#define STRING_IGNORES "\t\n "

struct TokenArray {
    char string_token[100];
    long token_array_size;
};

void print_token_array(struct TokenArray token_array[]) {
    for(int i = 0; i < token_array[i].token_array_size; i++) {
        printf("%s\n", token_array[i].string_token);
    }
}

void insert_tokens(struct TokenArray token_array[], char *token, int index, long file_size) {
    if(index < file_size) {
        strcpy(token_array[index].string_token, token);
    }
}

void insert_token_array_size(struct TokenArray token_array[]) {
    size_t token_array_length = 0;

    while(token_array[token_array_length].string_token != NULL) {
        token_array_length++;
        break;
    }

    token_array->token_array_size = token_array_length;
    return;
}

void build_token_stream(struct TokenArray token_array[], char *file_contents, struct FileData *file_data) {
    char *pch;
    int index = 0;
    long file_size = file_data->file_size;

    pch = strtok(file_contents, STRING_IGNORES);

    while (pch != NULL && index < file_size) {
        if(pch == NULL) {
            return;
        }

        insert_tokens(token_array, pch, index, file_size);
        index++;
    
        pch = strtok(NULL, STRING_IGNORES);
    }
}

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");

    struct FileData file_data;

    char *file_contents = read_in_nip_file(TEST_FILE_PATH, &file_data);
    long file_size = strnlen(file_contents, strlen(file_contents));

    struct TokenArray token_array[file_size];

    printf("[PARSED NIP FILE] %s\n", file_contents);

    printf("%ld", file_data.file_size);

    build_token_stream(token_array, file_contents, &file_data);
    insert_token_array_size(token_array);

    print_token_array(token_array);



    return 0;
}
