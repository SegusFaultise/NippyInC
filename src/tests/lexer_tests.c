#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../lexer/tokenizer.h"
#include "../lexer/ast.h"
#include "../file_functions_lib/file_functions.h"
#include "../color_print_lib/color_print.h"

#define TEST_RESULT_SIZE 7

#define PASSED "passed"
#define FAILED "failed"

void print_test(char *test_name, char test_result[TEST_RESULT_SIZE]) {
    primary_color();
    printf("TEST: ");
    reset_color();
    
    secondary_color();
    printf("%s", test_name);
    reset_color();

    primary_color();
    printf(" RESULT: ");
    reset_color();

    if(strcmp(test_result, PASSED) == 0) {
        tree_color();
        printf("%s \n", test_result);
        reset_color();
    }
    else {
        error_color();
        printf("%s \n", test_result);
        reset_color();
    }
}

void tokenizer_test(){
    char *nip_file = file_reader("../tests/add_operator_test.nip");

    tokenize(nip_file);
}

void add_operator_single_digits_test(struct AstNode *ast_root) {

    insert_token(&ast_root, "1", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "1", INTEGER);

    if(evaluate_ast(ast_root) == 2) {
        print_test("add_operator_single_digits_test", PASSED); 
    }
    if(evaluate_ast(ast_root) != 2) {
        print_test("add_operator", FAILED);
    }
}

void add_operator_multi_digits_test(struct AstNode *ast_root) {
    insert_token(&ast_root, "15", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "15", INTEGER);

    if(evaluate_ast(ast_root) == 30) {
        print_test("add_operator_multi_digits_test", PASSED);
    }
    if(evaluate_ast(ast_root) != 30) {
        print_test("add_operator", FAILED);
    }
}

void minus_operator_single_digits_test(struct AstNode *ast_root) {
    insert_token(&ast_root, "10", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "5", INTEGER);

    if(evaluate_ast(ast_root) == 5) {
        print_test("add_operator_multi_digits_test", PASSED);
    }
    if(evaluate_ast(ast_root) != 5) {
        print_test("add_operator", FAILED);
    }
}

int run_tests() {
    struct AstNode *ast_root = NULL;

    //tokenizer_test();
    add_operator_single_digits_test(ast_root);
    add_operator_multi_digits_test(ast_root);
    minus_operator_single_digits_test(ast_root);

    //free_ast(ast_root);

    printf("\n");

    return 0;
}
