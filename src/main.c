#include <stdio.h>

#include "file_functions.h"
#include "lexer.h"

int main() {
    printf("\nmain 0/n\n\n");

    char *file_lines = file_reader("../main.nip");

    tokenize(file_lines);

    return 0;
}
