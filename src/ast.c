#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"

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

    // Insert based on the type of the token
    if (type == ADDITION || type == MINUS || type == MULTIPLY || type == DIVIDE) {
        struct AstNode *new_node = create_node(type, token);
        new_node->left = *root;
        *root = new_node;
    } else {
        // Insert based on alphabetical order for keywords and variables
        int compareResult = strcmp(token, (*root)->token_alpha_value);
        if (compareResult < 0) {
            insert_token(&((*root)->left), token, type);
        } else if (compareResult > 0) {
            insert_token(&((*root)->right), token, type);
        }
        // Ignore if the token is already in the tree
    }}

int get_token_position(struct AstNode *root, const char *target_value) {
    if (root == NULL) {
        return -1;
    }

    if (strcmp(root->token_alpha_value, target_value) == 0) {
        return root->token_position;
    }

    int left_result = get_token_position(root->left, target_value);
    if (left_result != -1) {
        return left_result;
    }

    return get_token_position(root->right, target_value);
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

void primary() {
    printf("\033[1;36m");
}

void secondary() {
    printf("\033[1;34m");
}

void reset () {
    printf("\033[0m");
}

void in_order_traversal(struct AstNode *ast_root) {
    if(ast_root == NULL) {
        return;
    }
    in_order_traversal(ast_root->left);

    secondary();
    printf("AST NODE -> token_position: "); 

    primary();
    printf("( %d ) ", ast_root->token_position);

    secondary();
    printf(" || ");
    reset();

    secondary();
    printf("token_type: "); 

    primary();
    printf("[ %s ] ", token_type_enum_to_string(ast_root->token_type)); 

    secondary();
    printf(" || ");
    reset();

    secondary();
    printf("token_value: "); 

    primary();
    printf("[ '%s' ]", ast_root->token_alpha_value); 

    secondary();
    printf("\n");
    reset();

    in_order_traversal(ast_root->right);
}

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left) {
    if (ast_root != NULL) {
        printf("%s", prefix);
        printf(is_left ? "├── " : "└── ");

        printf("AST NODE: [ token_position: ( %d ) || token_type: ( %s ) || token_value: ( %s )",
                ast_root->token_position,
                token_type_enum_to_string(ast_root->token_type),
                ast_root->token_alpha_value);

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

