#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token_map.h"

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
            case END_OF_LINE:
                return "END_OF_LINE";
            case ASSIGN:
                return "ASSIGN";
            case UNDERSCORE:
                return "UNDERSCORE";
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

void insert_token(struct TokenMap token_map[], const char *token, enum TokenType type) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type == NUM_KEYS) {
            strcpy(token_map[i].token_value, token);

            token_map[i].token_type = type;

            break;
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

    printf("\n");
}
