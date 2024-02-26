#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <threads.h>

#include "../include/ast.h"
#include "../include/variable_map.h"
#include "../lib/color_printf_lib/include/color_print.h"

#define TRUE 0
#define FALSE 1

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
            case IF_STATEMENT:
                return "IF_STATMENT";
            case FOR_LOOP:
                return "FOR_LOOP";
            case WHILE_LOOP:
                return "WHILE_LOOP";
            case GREATER_THAN:
                return "GREATER_THAN";
            case LESS_THAN:
                return "LESS_THAN";
            case THAN_STATEMENT:
                return "THAN_STATEMENT";
            default:
                return NULL;
        }
    }
}

struct AstNode* create_node(enum TokenType type, const char *value) {
    struct AstNode *new_node = (struct AstNode*)malloc(sizeof(struct AstNode));

    if (new_node == NULL) {
        (void)printf("Error: Memory allocation failed!\n");
        (void)exit(EXIT_FAILURE);
    }

    new_node->token_type = type;

    (void)strcpy(new_node->token_alpha_value, value);

    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_token(struct AstNode **root, const char *token, enum TokenType type) {
    struct AstNode *new_node = (struct AstNode*)calloc(sizeof(root) + 1, sizeof(struct AstNode));

    if(*root == NULL) {
        *root = create_node(type, token);
        
        return;
    }

    if (new_node == NULL) {
        (void)printf("Error: Memory allocation failed!\n");
        (void)exit(EXIT_FAILURE);
    }

    while (*root != NULL) {
        int is_operator = (type == ADDITION || type == MULTIPLY || type == DIVIDE ||
                type == MINUS || type == GREATER_THAN || type == LESS_THAN);

        int is_alpha = (type == ALPHA);
        int is_assign = (type == ASSIGN);
        int is_integer = (type == INTEGER);
        int is_if_statement = (type == IF_STATEMENT);
        int is_while_loop = (type == WHILE_LOOP);
        int is_for_loop = (type == FOR_LOOP);
        int is_left_round_bracket = (type == LEFT_ROUND_BRACKET);
        int is_right_round_bracket = (type == RIGHT_ROUND_BRACKET);

        int token_type_is_operator = ((*root)->token_type == ADDITION || (*root)->token_type == MULTIPLY || 
                (*root)->token_type == DIVIDE || (*root)->token_type == MINUS) ||
                (*root)->token_type == GREATER_THAN || (*root)->token_type == LESS_THAN;

        if(is_if_statement) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == IF_STATEMENT && ((*root))->token_type != ALPHA) {
            root = &((*root)->right);
            continue;
        } 
        else if(is_left_round_bracket) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == LEFT_ROUND_BRACKET) {
            root = &((*root)->right);
            continue;
        } 
        else if(is_right_round_bracket) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == RIGHT_ROUND_BRACKET) {
            root = &((*root)->right);
            continue;
        } 

        if(is_alpha) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == ALPHA) {
            root = &((*root)->right);
        }
        else if(is_assign) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }
        else if (((*root))->token_type == ASSIGN) {
            root = &((*root)->right);
        } 
        
        else if(is_operator) {
            struct AstNode *new_root = (struct AstNode*)create_node(type, token);

            new_root->left = *root;
            *root = new_root;

            return;
        }

        else if (is_integer) {
            if (token_type_is_operator) {
                root = &((*root)->right);
            } 
            else {
                struct AstNode *new_root = (struct AstNode*)create_node(type, token);

                new_root->left = *root;
                *root = new_root;

                return;
            }
        } 
        else {
            int compareResult = (int)strcmp(token, (*root)->token_alpha_value);

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
    *root = (struct AstNode*)create_node(type, token);
}

int get_token_position(struct AstNode *root, const char *target_value) {
    int left_result = (int)get_token_position(root->left, target_value);

    if(root == NULL) {
        return -1;
    }
    if((int)strcmp(root->token_alpha_value, target_value) == 0) {
        return root->token_position;
    }
    if(left_result != -1) {
        return left_result;
    }

    return (int)get_token_position(root->right, target_value);
}

int evaluate_ast(struct AstNode *root) {
    struct VariableMap vairable_map[MAP_SIZE];

    const char *var_result = "";
    char *temp_string = (char*)malloc(strlen(var_result) + 1);

    if (root == NULL) {
        printf("Error: Cannot evaluate NULL node!\n");
        return 0;
    } 
    
    int result = 0;
    int if_result = FALSE; // Initialize if_result

    switch(root->token_type) {
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
            } else {
                fprintf(stderr, "ERROR CODE [1]: Division by zero is not allowed!\n");
                exit(-1);
            }
            break;
        }
        case GREATER_THAN: {
            int arg_one = evaluate_ast(root->left);
            int arg_two = evaluate_ast(root->right);
            if_result = (arg_one > arg_two) ? TRUE : FALSE;

            printf("%d\n", if_result);

            break;
        }
        case LESS_THAN: {
            int arg_one = evaluate_ast(root->left);
            int arg_two = evaluate_ast(root->right);
            if_result = (arg_one < arg_two) ? TRUE : FALSE;

            printf("%d\n", if_result);

            break;
        }
        case ALPHA: {
            // Handle variable retrieval
            result = (int)evaluate_ast(root->left);
            var_result = root->token_alpha_value;

            (void)strcpy(temp_string, var_result);

            break;
        }
        case ASSIGN: {
            // Handle variable assignment
            int value_to_assign = evaluate_ast(root->right);
            insert_variable(vairable_map, var_result, value_to_assign);
            result = value_to_assign; // Assigning result of assignment
            break;
        }
        case IF_STATEMENT: {
            // Evaluate if statement condition
            if_result = evaluate_ast(root->left);
            break;
        }
        case THAN_STATEMENT: {
            // Handle 'than' statement
            printf("THAN Statement not implemented!\n");
            break;
        }
    }
    
    if (if_result == TRUE) {
        result = evaluate_ast(root->right);

        printf("ITS TRUE \n");
        
    }
    else {
    
    }

    (void)get_variable_value_by_name(vairable_map, var_result);
    (void)free(temp_string);
    
    return result;
}

void free_ast(struct AstNode *node) {
    if (node == NULL) {
        return;
    }

    (void)free_ast(node->left);
    (void)free_ast(node->right);

    (void)free(node);

    node = NULL;
}

void print_tree_memory(struct AstNode *node) {
}

void in_order_traversal(struct AstNode *ast_root) {
    if(ast_root == NULL) {
        return;
    }

    (void)in_order_traversal(ast_root->left);

    (void)secondary_color();
    (void)printf("AST NODE -> token_position: "); 

    (void)primary_color();
    (void)printf("( %d ) ", ast_root->token_position);

    (void)secondary_color();
    (void)printf(" || ");
    (void)reset_color();

    (void)secondary_color();
    (void)printf("token_type: "); 

    (void)primary_color();
    (void)printf("[ %s ] ", token_type_enum_to_string(ast_root->token_type)); 

    (void)secondary_color();
    (void)printf(" || ");
    (void)reset_color();

    (void)secondary_color();
    (void)printf("token_value: "); 

    (void)primary_color();
    (void)printf("[ '%s' ]", ast_root->token_alpha_value); 

    (void)secondary_color();
    (void)printf("\n");
    (void)reset_color();

    (void)in_order_traversal(ast_root->right);
}

void print_tree(struct AstNode *root, enum TokenType type) {
    if(root == NULL) {
        return;
    }

    if(root->token_type == type) {
        (void)printf("Children of node %s of type %d:\n", root->token_alpha_value, type);

        if(root->left != NULL) {
            (void)printf("Left child: %s\n", root->left->token_alpha_value);
        } 
        else {
            (void)printf("No left child.\n");
        }

        if(root->right != NULL) {
            (void)printf("Right child: %s\n", root->right->token_alpha_value);
        } 
        else {
            (void)printf("No right child.\n");
        }
    }

    (void)print_tree(root->left, type);
    (void)print_tree(root->right, type);
}

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left) {
    char *temp_prefix = (char*)malloc(strlen(prefix) + 1);

    if(ast_root != NULL) {
        (void)printf("%s", prefix);

        (void)secondary_color();
        (void)printf(is_left ? "├── " : "└── ");

        (void)primary_color();
        (void)printf("NODE >> [TOKEN_TYPE]:");
        (void)reset_color();

        (void)secondary_color();
        (void)printf(" %s", token_type_enum_to_string(ast_root->token_type));
        (void)reset_color();
        
        (void)primary_color();
        (void)printf(", [TOKEN_VALUE]:");
        (void)reset_color();

        (void)secondary_color();
        (void)printf(" '%s' ", ast_root->token_alpha_value);
        (void)reset_color();

        (void)primary_color();

        if(ast_root->left != NULL || ast_root->right != NULL) {
            (void)printf("\n");

            char new_prefix[255];

            (void)snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

            (void)print_tree_structure(ast_root->left, new_prefix, 1);
            (void)print_tree_structure(ast_root->right, new_prefix, 0);
        } 
        else {
            (void)printf("\n");
        }
    }
}
