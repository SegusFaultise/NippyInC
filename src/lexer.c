#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "token_map.h"

struct TokenMap _token_map[MAP_SIZE];

char *extract_number(char *file_lines, int *index) {
    int start = *index;
    char *numeric_literal = (char*)malloc(*index - start + 1);

    while (isdigit(file_lines[*index])) {
        (*index)++;
    }

    if (numeric_literal != NULL) {
        strncpy(numeric_literal, file_lines + start, *index - start);
        numeric_literal[*index - start] = '\0';
    }
    return numeric_literal;

    free(numeric_literal);
}

char *extract_alpha(char *file_lines, int *i) {
    int start = *i;
    char *alpha_literal = (char*)malloc(*i - start + 1);

    while (isalpha((unsigned char)file_lines[*i])) {
        (*i)++;
    }
    
    if(alpha_literal == NULL) {
        printf("Error: alpha literal is null");
        free(alpha_literal);
    }
    else if (alpha_literal != NULL) {
        strncpy(alpha_literal, file_lines + start, *i - start);
        alpha_literal[*i - start] = '\0';
    }
    return alpha_literal;

    free(alpha_literal);
}

void tokenizer(char *file_lines) {
    initialize_token_map(_token_map);

    for(int i = 0; file_lines[i] != '\0'; i++) {
        if(isdigit(file_lines[i])) {
            insert_token(_token_map, extract_number(file_lines, &i), INTEGER);
        }
        else if(isalpha(file_lines[i])) {
            insert_token(_token_map, extract_alpha(file_lines, &i), ALPHA);
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
            case '=':
                insert_token(_token_map, "=", ASSIGN);
                break;
            case '_':
                insert_token(_token_map, "_", UNDERSCORE);
                break;
            default:
                printf("Unhandled character: %c (%d)\n", file_lines[i], file_lines[i]);
                break;
        }
    }
    get_token_value_based_on_type(_token_map, INTEGER);
    print_token_map(_token_map);
}
