#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"

struct AstNode ast_node[MAP_SIZE];

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

void insert_token(struct AstNode **token_map, const char *token, int position, enum TokenType type) {
    struct AstNode *temp_node = (struct AstNode*)malloc(sizeof(struct AstNode));

    temp_node->token_position = position;
    temp_node->token_type = type;
    strcpy(temp_node->token_value, token);

    temp_node->left = NULL;
    temp_node->right = NULL;

    if(!(*token_map)) {
        *token_map = temp_node;
        return;
    } 
    struct AstNode *current_node = *token_map;
    struct AstNode *parent_node = NULL;

    while(current_node != NULL) {
        parent_node = current_node;

        if(position < current_node->token_position) {
            current_node = current_node->left;
        }
        else if(position > current_node->token_position) {
            current_node = current_node->right;
        }
        else {
            free(temp_node);
            return;
        }
    }

    if(position < parent_node->token_position) {
        parent_node->left = temp_node;
    }
    else {
        parent_node->right = temp_node;
    }

}

void in_order_traversal(struct AstNode *ast_root) {
    if(ast_root != NULL) {
        in_order_traversal(ast_root->left);

        printf("AST NODE: [ token_position: ( %d ) || token_type: ( %s ) || token_value: ( %s ) ] ->\n", 
                ast_root->token_position, 
                token_type_enum_to_string(ast_root->token_type), 
                ast_root->token_value);

        in_order_traversal(ast_root->right);
    }
}
