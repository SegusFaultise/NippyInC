#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_SIZE 255

int size = 0;

enum TokenType {
    MULTIPLY,
    DIVIDE,
    ADDITION,
    MINUS,
    INTEGER,
    AND,
    LEFT_ROUND_BRACKET,
    RIGHT_ROUND_BRACKET,
    LEFT_SQUARE_BRACKET,
    RIGHT_SQUARE_BRACKET
};

struct TokenMap {
    char token_value[MAX_SIZE][100];
    enum TokenType token_type[MAX_SIZE];
};
struct TokenMap token_map;

int get_index(char key[]) { 
    for (int i = 0; i < size; i++) { 
        if (strcmp(token_map.token_value[i], key) == 0) { 
            return i; 
        } 
    } 
    return -1; // Key not found 
}

void insert_into_token_map(char value[], enum TokenType type) {
    int index = get_index(value);

    if(index == -1) {
        strcpy(token_map.token_value[size], value);

        token_map.token_type[size] = type;
        size++;
    }
    else {
        token_map.token_value[index] = type;
    }
}

void print_map() {
    struct TokenMap token_map;

    for(int i = 0; i < size; i++) {
        printf("%s: %d\n", token_map.token_value[i], token_map.token_type[i]);
    }
}

char *tokenizer(char *file_lines) {
    switch(*file_lines) {
        case '+':
            insert_into_token_map("+", ADDITION);

            break;
        case '-':

            break;
        case '/':

            break;
        case '*':

            break;
        case '(':

            break;
        case ')':

            break;
        case '{':

            break;
        case '}':

            break;
        case '&':

            break;
        default:

            break;
    }
    return "";
}


char *file_reader(char file_path[]) { 
    unsigned long buffer = 255;
    char *file_lines = malloc(buffer);

    FILE *fp = fopen(file_path, "r");

    if(fp == NULL) {
        printf("Error, file is NULL");

        return NULL;
    }
    while(fgets(file_lines, buffer, fp)) {
        printf("%s", file_lines);
    }
    
    fclose(fp);

    return file_path;
}

int main() {
    printf("\nmain 0/n\n\n");

    char *file_lines = file_reader("main.nip");

    tokenizer(file_lines);

    print_map();

    return 0;
}
