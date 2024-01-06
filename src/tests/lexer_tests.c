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

void print_test(const char *test_name, char test_result[TEST_RESULT_SIZE]) {
    char *temp_string = malloc(strlen(test_name) + 1);
    
    primary_color();
    printf("[TEST]: ");
    reset_color();

    secondary_color();
    printf("%s\t\t\t\t", strcpy(temp_string, test_name));
    reset_color();

    primary_color();
    printf("[RESULT]: ");
    reset_color();

    if(strcmp(test_result, PASSED) == 0) {
        tree_color();
        printf("%s\n", PASSED);
        reset_color();

        free(temp_string);
    }
    else if(strcmp(test_result, FAILED) == 0) {
        error_color();
        printf("%s\n", FAILED);
        reset_color();

        free(temp_string);
    }
    else {
        free(temp_string);
    }
}

void tokenizer_test(){
    char *nip_file = file_reader("../tests/test_file.nip");

    tokenize(nip_file);
}

void addition_operation_single_digits_test(struct AstNode *ast_root) {
    int result = 1 + 1;

    insert_token(&ast_root, "1", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "1", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED); 
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void addition_operation_multi_digits_test(struct AstNode *ast_root) {
    int result = 15 + 15;

    insert_token(&ast_root, "15", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "15", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void minus_operation_single_digits_test(struct AstNode *ast_root) {
    int result = 3 - 2;

    insert_token(&ast_root, "3", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "2", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void minus_operation_multi_digits_test(struct AstNode *ast_root) {
    int result = 10 - 5;

    insert_token(&ast_root, "10", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "5", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void multiply_operation_single_digits_test(struct AstNode *ast_root) {
    int result = 2 * 2;

    insert_token(&ast_root, "2", INTEGER);
    insert_token(&ast_root, "*", MULTIPLY);
    insert_token(&ast_root, "2", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void multiply_operation_multi_digits_test(struct AstNode *ast_root) {
    int result = 12 * 12;

    insert_token(&ast_root, "12", INTEGER);
    insert_token(&ast_root, "*", MULTIPLY);
    insert_token(&ast_root, "12", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void divide_operation_single_digits_test(struct AstNode *ast_root) {
    int result = 8 / 4;

    insert_token(&ast_root, "8", INTEGER);
    insert_token(&ast_root, "/", DIVIDE);
    insert_token(&ast_root, "4", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void divide_operation_multi_digits_test(struct AstNode *ast_root) {
    int result = 32 / 12;

    insert_token(&ast_root, "32", INTEGER);
    insert_token(&ast_root, "/", DIVIDE);
    insert_token(&ast_root, "12", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void all_math_operations_single_digits_test(struct AstNode *ast_root) {
    int result = 5 + 5 - 5 * 2 / 2;

    insert_token(&ast_root, "5", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "5", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "5", INTEGER);
    insert_token(&ast_root, "*", MULTIPLY);
    insert_token(&ast_root, "2", INTEGER);
    insert_token(&ast_root, "/", DIVIDE);
    insert_token(&ast_root, "2", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }
}

void all_math_operations_multi_digits_test(struct AstNode *ast_root) {
    /*
     * (!) C has a diffrent order of operations
     *
     * this test has been tested with a calculator
     * int result = 15 + 15 - 12 * 10 / 32;
     *
     */

    insert_token(&ast_root, "15", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "15", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "12", INTEGER);
    insert_token(&ast_root, "*", MULTIPLY);
    insert_token(&ast_root, "32", INTEGER);
    insert_token(&ast_root, "/", DIVIDE);
    insert_token(&ast_root, "10", INTEGER);

    if(evaluate_ast(ast_root) == 57) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != 57) {
        print_test(__func__, FAILED);
    }
}

void alpha_prefix_for_addition_operations_test(struct AstNode *ast_root) {
    int result = 4 + 2;

    insert_token(&ast_root, "var_name", ALPHA);
    insert_token(&ast_root, "=", ASSIGN);
    insert_token(&ast_root, "4", INTEGER);
    insert_token(&ast_root, "+", ADDITION);
    insert_token(&ast_root, "2", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }

}

void alpha_prefix_for_minus_operations_test(struct AstNode *ast_root) {
    int result = 10 - 2;

    insert_token(&ast_root, "var_name", ALPHA);
    insert_token(&ast_root, "=", ASSIGN);
    insert_token(&ast_root, "10", INTEGER);
    insert_token(&ast_root, "-", MINUS);
    insert_token(&ast_root, "2", INTEGER);

    if(evaluate_ast(ast_root) == result) {
        print_test(__func__, PASSED);
    }
    else if(evaluate_ast(ast_root) != result) {
        print_test(__func__, FAILED);
    }

}

int run_tests() {
    struct AstNode *ast_root = NULL;

    tokenizer_test();

    addition_operation_single_digits_test(ast_root);
    addition_operation_multi_digits_test(ast_root);

    minus_operation_single_digits_test(ast_root);
    minus_operation_multi_digits_test(ast_root);

    multiply_operation_single_digits_test(ast_root);
    multiply_operation_multi_digits_test(ast_root);

    divide_operation_single_digits_test(ast_root);
    divide_operation_multi_digits_test(ast_root);

    all_math_operations_single_digits_test(ast_root);
    all_math_operations_multi_digits_test(ast_root);

    alpha_prefix_for_addition_operations_test(ast_root);
    alpha_prefix_for_minus_operations_test(ast_root);

    free_ast(ast_root);

    printf("\n");

    return 0;
}
