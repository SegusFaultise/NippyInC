#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "ast.h"

struct AstNode *_ast_node = NULL;

char *extract_number(char *file_lines, int *index) {
    int start = *index;
    char *numeric_literal = (char*)malloc(*index - start + 1);

    while (isdigit(file_lines[*index])) {
        (*index)++;
    }

    if(numeric_literal != NULL) {
        strncpy(numeric_literal, file_lines + start, *index - start);

        numeric_literal[*index - start] = '\0';
    }
    return numeric_literal;
}

char *extract_alpha(char *file_lines, int *i) {
    int start = *i;
    char *alpha_literal = (char*)malloc(*i - start + 1);

    while(isalpha((unsigned char)file_lines[*i])) {
        (*i)++;
    }

    if(alpha_literal == NULL) {
        printf("Error: alpha literal is null");
        free(alpha_literal);
    }
    else if(alpha_literal != NULL) {
        strncpy(alpha_literal, file_lines + start, *i - start);

        alpha_literal[*i - start] = '\0';
    }
    return alpha_literal;
}

void print_children(struct AstNode *node, int level) {
    if (node == NULL) {
        return;
    }

    // Print the current node
    printf("%*s", level * 4, "");  // Adjust the indentation based on the level
    printf("AST NODE: [ token_position: ( %d ) || token_type: ( %d ) || token_value: ( %s ) ]\n",
           node->token_position, node->token_type, node->token_alpha_value);

    // Recursively print the left and right children
    print_children(node->left, level + 1);
    print_children(node->right, level + 1);
}

void tokenize(char *file_lines) {
    for(int i = 0; file_lines[i] != '\0'; i++) {
        if(isdigit(file_lines[i])) {
            insert_token(&_ast_node, extract_number(file_lines, &i), INTEGER);
        }
        else if(isalpha(file_lines[i])) {
            insert_token(&_ast_node, extract_alpha(file_lines, &i), ALPHA);
        }

        switch(file_lines[i]) {
            case '\n':
                continue;
            case '+':
                insert_token(&_ast_node, "+", ADDITION);
                break;
            case '-':
                insert_token(&_ast_node, "-", MINUS);
                break;
            case '/':
                insert_token(&_ast_node, "/", DIVIDE);
                break;
            case '*':
                insert_token(&_ast_node, "*", MULTIPLY);
                break;
            case '(':
                insert_token(&_ast_node, "(", LEFT_ROUND_BRACKET);
                break;
            case ')':
                insert_token(&_ast_node, ")", RIGHT_ROUND_BRACKET);
                break;
            case '{':
                insert_token(&_ast_node, "{", LEFT_SQUARE_BRACKET);
                break;
            case '}':
                insert_token(&_ast_node, "}", RIGHT_SQUARE_BRACKET);
                break;
            case '&':
                insert_token(&_ast_node, "&", AND);
                break;
            case ';':
                insert_token(&_ast_node, ";", END_OF_LINE);
                break;
            case '=':
                insert_token(&_ast_node, "=", ASSIGN);
                break;
            case '_':
                insert_token(&_ast_node, "_", UNDERSCORE);
                break;
            default:
                printf("Unhandled character: [ %c ] (%d)\n", file_lines[i], file_lines[i]);
                break;
        }
    }

    in_order_traversal(_ast_node);

    int result = evaluate_ast(_ast_node);
    printf("%d \n", result);
    //
    //print_tree_structure(_ast_node, "", 0);
    print_children(_ast_node, 0);

    free_ast(_ast_node);
}

void test() {
    //evaluate_ast(*_ast_node);
}
