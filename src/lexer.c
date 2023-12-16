#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "token_map.h"

struct TokenMap _token_map[MAP_SIZE];

char *extract_number(char *file_lines, int *index) {
    int start = *index;

    while (isdigit(file_lines[*index])) {
        (*index)++;
    }

    // Allocate memory for the numeric literal
    char *numeric_literal = (char*)malloc(*index - start + 1);

    if (numeric_literal != NULL) {
        strncpy(numeric_literal, file_lines + start, *index - start);
        numeric_literal[*index - start] = '\0';
    }

    return numeric_literal;
}

char *extract_word(char *file_lines, int *i) {
    int start = *i;

    while (isalpha((unsigned char)file_lines[*i])) {
        (*i)++;
    }

    // Allocate memory for the word
    char *word = (char*)malloc(*i - start + 1);

    if (word != NULL) {
        strncpy(word, file_lines + start, *i - start);
        word[*i - start] = '\0';
    }

    return word;
}

void *tokenizer(char *file_lines) {
    initialize_token_map(_token_map);
    
    //printf("%s\n", file_lines);

    for(int i = 0; file_lines[i] != '\0'; i++) {
        if(isdigit(file_lines[i])) {
            insert_token(_token_map, extract_number(file_lines, &i), INTEGER);
        }
        else if(isalpha(file_lines[i])) {
            insert_token(_token_map, extract_word(file_lines, &i), ALPHA);
        }

        switch(file_lines[i]) {
            case '\n':
                continue;
            case '+':
                insert_token(_token_map, "+", ADDITION);
                break;
            case '-':
                insert_token(_token_map, "-", MINUS);
                break;
            case '/':
                insert_token(_token_map, "/", DIVIDE);
                break;
            case '*':
                insert_token(_token_map, "*", MULTIPLY);
                break;
            case '(':
                insert_token(_token_map, "(", LEFT_ROUND_BRACKET);
                break;
            case ')':
                insert_token(_token_map, ")", RIGHT_ROUND_BRACKET);
                break;
            case '{':
                insert_token(_token_map, "{", LEFT_SQUARE_BRACKET);
                break;
            case '}':
                insert_token(_token_map, "}", RIGHT_SQUARE_BRACKET);
                break;
            case '&':
                insert_token(_token_map, "&", AND);
                break;
            case ';':
                insert_token(_token_map, ";", END_OF_LINE);
                break;
            default:
                printf("Unhandled character: %c (%d)\n", file_lines[i], file_lines[i]);
                break;
        }
    }
    print_token_map(_token_map);
}
