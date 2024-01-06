#include <malloc.h>
#include <ctype.h>
#include <stdbool.h>
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
    if (file_lines == NULL || *i < 0 || file_lines[*i] == '\0') {
        return NULL;
    }

    int start = *i;
    char *alpha_literal = NULL;
    int length = 0;

    while (isalpha((unsigned char)file_lines[*i]) || file_lines[*i] == '_') {
        (*i)++;
        length++;
    }

    if (length > 0) {
        alpha_literal = (char *)malloc(length + 1); 

        if (alpha_literal == NULL) {
            printf("Error: Memory allocation failed");
            return NULL;
        }

        strncpy(alpha_literal, file_lines + start, length);
        alpha_literal[length] = '\0';
    }

    return alpha_literal;
}

void tokenize(char *file_lines) {
    for(int i = 0; file_lines[i] != '\0'; i++) {
        if(isdigit(file_lines[i])) {
            insert_token(&_ast_node, extract_number(file_lines, &i), INTEGER);
        }
        if(isalpha(file_lines[i])) {
            insert_token(&_ast_node, extract_alpha(file_lines, &i), ALPHA);
        }
        else {
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
                case ' ':
                    continue;
                default:
                    printf("Unhandled character: [ %c ] (%d)\n", file_lines[i], file_lines[i]);
                    break;
            }
        }
    }

    printf("\n");
    in_order_traversal(_ast_node);
    printf("\n");

    printf("AST TREE\n");
    print_tree_structure(_ast_node, "", 0);

    print_tree(_ast_node, ADDITION);
    printf("\n");

    int result = evaluate_ast(_ast_node);
    printf("AST Eval Result: [ %d ] \n\n", result);

    free_ast(_ast_node);
}
