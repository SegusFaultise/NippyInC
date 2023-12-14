#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#define MAX_SIZE 50
#define MAP_SIZE 100

enum TokenType {
    MULTIPLY,
    DIVIDE,
    ADDITION,
    MINUS,
    INTEGER,
    ALPHA,
    AND,
    LEFT_ROUND_BRACKET,
    RIGHT_ROUND_BRACKET,
    LEFT_SQUARE_BRACKET,
    RIGHT_SQUARE_BRACKET,
    NUM_KEYS
};

struct TokenMap {
    char token_value[MAX_SIZE];
    enum TokenType token_type;
};
struct TokenMap token_map[MAP_SIZE];

char *token_type_enum_to_string(enum TokenType token_type) {
    if(token_type == NUM_KEYS) {
        return NULL;
    }
    else {
        switch(token_type) {
            case MULTIPLY:
                return "MULTIPLY";
            case DIVIDE:
                return "DIVIDE";
            case ADDITION:
                return "ADDITION";
            case MINUS:
                return "MINUS";
            case INTEGER:
                return "INTEGER";
            case ALPHA:
                return "ALPHA";
            case AND:
                return "AND";
            case LEFT_ROUND_BRACKET:
                return "LEFT_ROUND_BRACKET";
            case RIGHT_ROUND_BRACKET:
                return "RIGHT_ROUND_BRACKET";
            case LEFT_SQUARE_BRACKET:
                return "LEFT_SQUARE_BRACKET";
            case RIGHT_SQUARE_BRACKET:
                return "RIGHT_SQUARE_BRACKET";
            case NUM_KEYS:
                return "NUM_KEYS";
            default:
                return NULL;
        }
    }
}

void initialize_token_map(struct TokenMap token_map[]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        token_map[i].token_type = NUM_KEYS;

        strcpy(token_map[i].token_value, "");
    }
}

void insert_token(struct TokenMap token_map[], char *token, enum TokenType type) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type == NUM_KEYS) {
            strcpy(token_map[i].token_value, token);
            token_map[i].token_type = type;
            return;
        }
    }
}

void print_token_map(struct TokenMap token_map[]) {
    printf("\n");

    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type != NUM_KEYS) {
            printf("Token Value: [ %s ] | Token Type: [ %s ]\n", token_map[i].token_value, token_type_enum_to_string(token_map[i].token_type));
        }
    }
}

char *extract_number(char *file_lines, int *index) {
    int start = *index;
    char *numeric_literal = (char*)malloc(*index - start + 1);

    while(isdigit(file_lines[*index])) {
        (*index)++;    
    }
    strncpy(numeric_literal, file_lines + start, *index - start);

    numeric_literal[*index - start] = '\0';

    return numeric_literal;

    free(numeric_literal);
}

char *extract_word(char *file_lines, int *i) {
    int start = *i;
    char *word = (char*)malloc(*i - start + 1);

    while (isalpha((unsigned char)file_lines[*i])) {
        (*i)++;
    }
    strncpy(word, file_lines + start, *i - start);

    word[*i - start] = '\0';

    return word;

    free(word);
}


// func
char *tokenizer(char *file_lines) {
    initialize_token_map(token_map);

    for(int i = 0; file_lines[i] != '\0'; i++) {
        switch(file_lines[i]) {
            case '+':
                insert_token(token_map, "+", ADDITION);
                break;
            case '-':
                insert_token(token_map, "-", MINUS);
                break;
            case '/':
                insert_token(token_map, "/", DIVIDE);
                break;
            case '*':
                insert_token(token_map, "*", MULTIPLY);
                break;
            case '(':
                insert_token(token_map, "(", LEFT_ROUND_BRACKET);
                break;
            case ')':
                insert_token(token_map, ")", RIGHT_ROUND_BRACKET);
                break;
            case '{':
                insert_token(token_map, "{", LEFT_SQUARE_BRACKET);
                break;
            case '}':
                insert_token(token_map, "}", RIGHT_SQUARE_BRACKET);
                break;
            case '&':
                insert_token(token_map, "&", AND);
                break;
            default:
                if(isdigit(file_lines[i])) {
                    insert_token(token_map, extract_number(file_lines, &i), INTEGER);
                }
                if(isalpha(file_lines[i])) {
                    insert_token(token_map, extract_word(file_lines, &i), ALPHA);
                }
                break;
        }
    }
    print_token_map(token_map);

    return "";
}

char *file_reader(char file_path[]) {
    FILE *fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Error, file is NULL");
        return NULL;
    }

    unsigned long buffer_size = 255;
    char *file_lines = malloc(buffer_size);

    if (file_lines == NULL) {
        perror("Memory allocation error");
        fclose(fp);
        return NULL;
    }

    size_t total_size = 0;
    char *line;

    while((line = fgets(file_lines + total_size, buffer_size - total_size, fp)) != NULL) {
        total_size += strlen(line);

        if (total_size + buffer_size > buffer_size) {
            buffer_size *= 2;
            file_lines = realloc(file_lines, buffer_size);

            if (file_lines == NULL) {
                perror("Memory reallocation error");
                fclose(fp);
                return NULL;
            }
        }
    }
    fclose(fp);
    printf("%s", file_lines);

    return file_lines;
}

int main() {
    printf("\nmain 0/n\n\n");

    char *file_lines = file_reader("../main.nip");

    tokenizer(file_lines);

    return 0;
}
