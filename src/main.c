#include <stdio.h>

#include "../lib/file_functions_lib/include/file_functions.h"
#include "../include/tokenizer.h"
#include "../tests/include/lexer_tests.h"

int main() {
    printf("\nRunning from main.c ...\n\n");

    //char *file_lines = file_reader("../main.nip");
    //tokenize(file_lines);

    run_tests();

    return 0;
}
