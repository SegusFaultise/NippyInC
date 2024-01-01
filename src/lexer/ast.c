#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "../color_print_lib/color_print.h"

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

struct AstNode* create_node(enum TokenType type, const char *value) {
    struct AstNode *new_node = (struct AstNode*)malloc(sizeof(struct AstNode));

    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->token_type = type;

    strcpy(new_node->token_alpha_value, value);

    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_token(struct AstNode **root, const char *token, enum TokenType type) {
    if (*root == NULL) {
        *root = create_node(type, token);

        return;
    }

    int is_operator = (type == ADDITION || type == MULTIPLY || type == DIVIDE || type == MINUS);
    int is_alpha = (type == ALPHA);
    int is_integer = (type == INTEGER);
    int token_type_is_operator = ((*root)->token_type == ADDITION || (*root)->token_type == MULTIPLY || 
                                  (*root)->token_type == DIVIDE || (*root)->token_type == MINUS);

    if(is_alpha) {
        struct AstNode *new_root = create_node(type, token);

        new_root->left = *root;
        *root = new_root;
    }
    else if(is_operator) {
        struct AstNode *new_root = create_node(type, token);

        new_root->left = *root;
        *root = new_root;
    }
    else if(is_integer) {
        if(token_type_is_operator) {

            insert_token(&((*root)->right), token, type);
        } 
        else {
            struct AstNode *new_root = create_node(type, token);

            new_root->left = *root;
            *root = new_root;
        }
    } 
    else {
        int compareResult = strcmp(token, (*root)->token_alpha_value);

        if(compareResult < 0) {
            insert_token(&((*root)->left), token, type);
        } 
        else if(compareResult > 0) {
            insert_token(&((*root)->right), token, type);
        }
    }
}

int get_token_position(struct AstNode *root, const char *target_value) {
    int left_result = get_token_position(root->left, target_value);

    if (root == NULL) {
        return -1;
    }
    if (strcmp(root->token_alpha_value, target_value) == 0) {
        return root->token_position;
    }
    if (left_result != -1) {
        return left_result;
    }

    return get_token_position(root->right, target_value);
}

void print_arr(int arr[]) {
    for(int i = 0; i < 1; i++) {
        printf("Results: [ %d ] \n\n", arr[i]);
    }
}

// TODO: build peek_next_token() function that returns the next token whith type enum TokenType or string
int evaluate_ast(struct AstNode *root) {
    if (root == NULL) {
        printf("Error: Cannot evaluate NULL node!\n");
        return 0;
    }

    switch (root->token_type) {
        case INTEGER:
            return atoi(root->token_alpha_value);
        case ADDITION:
            return evaluate_ast(root->left) + evaluate_ast(root->right);
        case MINUS:
            return evaluate_ast(root->left) - evaluate_ast(root->right);
        case MULTIPLY:
            return evaluate_ast(root->left) * evaluate_ast(root->right);
        case DIVIDE:
            return evaluate_ast(root->left) / evaluate_ast(root->right);
        case ASSIGN:
        case ALPHA:
            printf("Variable '%s' encountered during evaluation.\n", root->token_alpha_value);
            return 0;
        default:
            printf("Error: Invalid node type!\n");
            return 0;
    }
}

void free_ast(struct AstNode *node) {
    if (node == NULL) {
        return;
    }

    free_ast(node->left);
    free_ast(node->right);

    free(node);
}

void in_order_traversal(struct AstNode *ast_root) {
    if(ast_root == NULL) {
        return;
    }

    in_order_traversal(ast_root->left);

    secondary_color();
    printf("AST NODE -> token_position: "); 

    primary_color();
    printf("( %d ) ", ast_root->token_position);

    secondary_color();
    printf(" || ");
    reset_color();

    secondary_color();
    printf("token_type: "); 

    primary_color();
    printf("[ %s ] ", token_type_enum_to_string(ast_root->token_type)); 

    secondary_color();
    printf(" || ");
    reset_color();

    secondary_color();
    printf("token_value: "); 

    primary_color();
    printf("[ '%s' ]", ast_root->token_alpha_value); 

    secondary_color();
    printf("\n");
    reset_color();

    in_order_traversal(ast_root->right);
}

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left) {
    if (ast_root != NULL) {
        printf("%s", prefix);

        primary_color();
        printf(is_left ? "├── " : "└── ");
        
        secondary_color();
        printf("AST NODE: [ token_position: ( %d ) || token_type: ( %s ) || token_value: ( %s )",
                ast_root->token_position,
                token_type_enum_to_string(ast_root->token_type),
                ast_root->token_alpha_value);
        reset_color();

        primary_color();

        if (ast_root->left != NULL || ast_root->right != NULL) {
            printf("\n");

            char new_prefix[255];
            snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

            print_tree_structure(ast_root->left, new_prefix, 1);
            print_tree_structure(ast_root->right, new_prefix, 0);
        } else {
            printf(" ]\n");
        }
    }
}
