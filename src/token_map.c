#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token_map.h"
#include "ast.h"

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
        token_map[i].token_position = 0;

        strcpy(token_map[i].token_value, "");
    }
}

void insert_token(struct TokenMap token_map[], const char *token, int position, enum TokenType type) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type == NUM_KEYS) {
            strcpy(token_map[i].token_value, token);

            token_map[i].token_position = position;
            token_map[i].token_type = type;

            break;
        }
    }
}

char *get_token_value_based_on_type(struct TokenMap token_map[], enum TokenType type) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type == type) {
            printf("\nFound Token Type ->  %s \n", token_type_enum_to_string(token_map[i].token_type));

            return token_map[i].token_value;
        }
        else if(token_map[i].token_type == NUM_KEYS){
            continue;
        }
    }
    printf("Token not found");
    return NULL;
}

void add_token_positions_to_ast(struct TokenMap token_map[]) {
    struct AstNode *ast_root = NULL;

    for(int i = 0; i < MAP_SIZE; i++) {
        insert_ast_node(&ast_root, token_map[i].token_position);
        
    }
    printf("AST: ");

    in_order_traversal(ast_root);

    printf("\n");
}

void print_token_map(struct TokenMap token_map[]) {
    printf("\n");

    for(int i = 0; i < MAP_SIZE; i++) {
        if(token_map[i].token_type != NUM_KEYS) {
            printf("Token Value: [ %s ] | Token Type: [ %s ] | Token position: %d\n", 
                    token_map[i].token_value, 
                    token_type_enum_to_string(token_map[i].token_type), 
                    token_map[i].token_position);
        }
    }
    printf("\n");
}
