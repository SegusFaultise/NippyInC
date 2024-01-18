#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"
#include "variable_map.h"
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
    struct AstNode *new_node = (struct AstNode*)malloc(sizeof(struct AstNode));

    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    while (*root != NULL) {
        int is_operator = (type == ADDITION || type == MULTIPLY || type == DIVIDE || type == MINUS);
        int is_alpha = (type == ALPHA);
        int is_assign = (type == ASSIGN);
        int is_integer = (type == INTEGER);
        int token_type_is_operator = ((*root)->token_type == ADDITION || (*root)->token_type == MULTIPLY ||
                (*root)->token_type == DIVIDE || (*root)->token_type == MINUS);

        if(is_alpha) {
            struct AstNode *new_root = create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == ALPHA) {
            root = &((*root)->right);
        }
        else if(is_assign) {
            struct AstNode *new_root = create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == ASSIGN) {
            root = &((*root)->right);
        } 
        else if(is_operator) {
            struct AstNode *new_root = create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (is_integer) {
            if (token_type_is_operator) {
                root = &((*root)->right);
            } 
            else {
                struct AstNode *new_root = create_node(type, token);

                new_root->left = *root;
                *root = new_root;

                return;
            }
        } 
        else {
            int compareResult = strcmp(token, (*root)->token_alpha_value);

            if (compareResult < 0) {
                root = &((*root)->left);
            } 
            else if (compareResult > 0) {
                root = &((*root)->right);
            } 
            else {
                return;
            }
        }
    }

    *root = create_node(type, token);
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

int evaluate_ast(struct AstNode *root) {
    struct VariableMap vairable_map[MAP_SIZE];

    int result = 0;
    const char *var_result = "";

    char *temp_string = malloc(strlen(var_result) + 1);

    if (root == NULL) {
        printf("Error: Cannot evaluate NULL node!\n");
        return 0;
    } 
    else {
        switch (root->token_type) {
            case INTEGER:
                result = atoi(root->token_alpha_value);
                break;
            case ADDITION:
                result = evaluate_ast(root->left) + evaluate_ast(root->right);
                break;
            case MINUS:
                result = evaluate_ast(root->left) - evaluate_ast(root->right);
                break;
            case MULTIPLY:
                result = evaluate_ast(root->left) * evaluate_ast(root->right);
                break;
            case DIVIDE: {
                int divisor = evaluate_ast(root->right);

                if (divisor != 0) {
                    result = evaluate_ast(root->left) / divisor;
                } 
                else {
                    fprintf(stderr, "ERROR CODE [1]: No division by zero silly!");
                    exit(-1);
                }
                break;
            }
            case ALPHA:
                result = evaluate_ast(root->left);
                var_result = root->token_alpha_value;

                strcpy(temp_string, var_result);
                //break;
            case ASSIGN:
                result = evaluate_ast(root->right);
                //break;
                //
                insert_variable(vairable_map, var_result, result);
                break;
            case END_OF_LINE:
                //result = evaluate_ast(root->right);
                //printf("alpha_result [ %s ]", alpha_result);
                
                //insert_variable(vairable_map, var_result, result);
                break;
        }
    }
    print_variable_map(vairable_map);
    free(temp_string);
    return result;
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

void print_tree(struct AstNode *root, enum TokenType type) {
    if (root == NULL) {
        return;
    }

    if (root->token_type == type) {
        printf("Children of node %s of type %d:\n", root->token_alpha_value, type);
        if (root->left != NULL) {
            printf("Left child: %s\n", root->left->token_alpha_value);
        } else {
            printf("No left child.\n");
        }

        if (root->right != NULL) {
            printf("Right child: %s\n", root->right->token_alpha_value);
        } else {
            printf("No right child.\n");
        }
    }

    print_tree(root->left, type);
    print_tree(root->right, type);
}

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left) {
    char *temp_prefix = malloc(strlen(prefix) + 1);

    if (ast_root != NULL) {
        printf("%s", prefix);

        secondary_color();
        printf(is_left ? "├── " : "└── ");

        primary_color();
        printf("NODE >> [TOKEN_TYPE]:");
        reset_color();

        secondary_color();
        printf(" %s", token_type_enum_to_string(ast_root->token_type));
        reset_color();
        
        primary_color();
        printf(", [TOKEN_VALUE]:");
        reset_color();

        secondary_color();
        printf(" '%s' ", ast_root->token_alpha_value);
        reset_color();

        primary_color();

        if (ast_root->left != NULL || ast_root->right != NULL) {
            printf("\n");

            char new_prefix[255];
            snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

            print_tree_structure(ast_root->left, new_prefix, 1);
            print_tree_structure(ast_root->right, new_prefix, 0);
        } else {
            printf("\n");
        }
    }
}
