#include <malloc.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../include/ast.h"

#define IF_KEY_WORD "if"
#define FOR_KEY_WORD "for"
#define WHILE_KEY_WORD "while"

struct AstNode *_ast_node = NULL;

char *extract_number(char *file_lines, int *index) {
    int start = *index;
    char *numeric_literal = (char*)malloc(*index - start + 1);

    while ((int)isdigit(file_lines[*index])) {
        (*index)++;
    }
    if(numeric_literal == NULL) {
        (void)printf("Error: Memory allocation failed");
        (void)free(numeric_literal);

        return NULL;
    }
    else if(numeric_literal != NULL) {
        (void)strncpy(numeric_literal, file_lines + start, *index - start);

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

    while ((int)isalpha((unsigned char)file_lines[*i]) || file_lines[*i] == '_') {
        (*i)++;
        length++;
    }
    if (length > 0) {
        alpha_literal = (char *)malloc(length + 1); 

        if (alpha_literal == NULL) {
            (void)printf("Error: Memory allocation failed");
            (void)free(alpha_literal);

            return NULL;
        }
        (void)strncpy(alpha_literal, file_lines + start, length);

        alpha_literal[length] = '\0';
    }

    return alpha_literal;
}

void tokenize(char *file_lines) {
    for(int i = 0; file_lines[i] != '\0'; i++) {
        if(isdigit(file_lines[i])) (void)insert_token(&_ast_node, (char*)extract_number(file_lines, &i), INTEGER);
        if(isalpha(file_lines[i])) {
            char *extracted_alpha = (char*)extract_alpha(file_lines, &i);

            int if_cmp = (int)strcmp(IF_KEY_WORD, extracted_alpha);
            int for_cmp = (int)strcmp(FOR_KEY_WORD, extracted_alpha); 
            int while_cmp = (int)strcmp(WHILE_KEY_WORD, extracted_alpha); 

            if(if_cmp == 0) (void)insert_token(&_ast_node, extracted_alpha, IF_STATEMENT);
            if(for_cmp == 0) (void)insert_token(&_ast_node, extracted_alpha, FOR_LOOP);
            if(while_cmp == 0) (void)insert_token(&_ast_node, extracted_alpha, WHILE_LOOP);

            else if(if_cmp != 0 || for_cmp != 0 || while_cmp != 0) continue;
            else (void)insert_token(&_ast_node, (char*)extract_alpha(file_lines, &i), ALPHA);
        }
        else {
            switch(file_lines[i]) {
                case '\n': 
                    continue;
                case '+':
                    (void)insert_token(&_ast_node, "+", ADDITION);
                    break;
                case '-':
                    (void)insert_token(&_ast_node, "-", MINUS);
                    break;
                case '/':
                    (void)insert_token(&_ast_node, "/", DIVIDE);
                    break;
                case '*':
                    (void)insert_token(&_ast_node, "*", MULTIPLY);
                    break;
                case '(':
                    (void)insert_token(&_ast_node, "(", LEFT_ROUND_BRACKET);
                    break;
                case ')':
                    (void)insert_token(&_ast_node, ")", RIGHT_ROUND_BRACKET);
                    break;
                case '{':
                    (void)insert_token(&_ast_node, "{", LEFT_SQUARE_BRACKET);
                    break;
                case '}':
                    (void)insert_token(&_ast_node, "}", RIGHT_SQUARE_BRACKET);
                    break;
                case '&':
                    (void)insert_token(&_ast_node, "&", AND);
                    break;
                case ';':
                    (void)insert_token(&_ast_node, ";", END_OF_LINE);
                    break;
                case '=':
                    (void)insert_token(&_ast_node, "=", ASSIGN);
                    break;
                case ' ':
                    continue;
                default:
                    (void)printf("Unhandled character: [ %c ] (%d)\n", file_lines[i], file_lines[i]);
                    break;
            }
        }
    }

    (void)printf("\n");
    (void)in_order_traversal(_ast_node);
    (void)printf("\n");

    (void)printf("AST TREE\n");
    (void)print_tree_structure(_ast_node, "", 0);

    (void)print_tree(_ast_node, ADDITION);
    (void)printf("\n");

    int result = (int)evaluate_ast(_ast_node);

    (void)printf("AST Eval Result: [ %d ] \n\n", result);

    (void)free_ast(_ast_node);
}
