#include <stdio.h>

#include "file_functions_lib/file_functions.h"
#include "lexer/tokenizer.h"
#include "tests/lexer_tests.h"

int main() {
    printf("\nRunning from main.c ...\n\n");

    char *file_lines = file_reader("../main.nip");
    tokenize(file_lines);

    //run_tests();

    return 0;
}
