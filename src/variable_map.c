#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

struct VariableMap {
    char *variable_name;
    int variable_value_int;
};

void insert_variable(struct VariableMap *variable_map[], const char *variable_name, int variable_value_int) {
    struct VariableMap *new_map = (struct VariableMap*)malloc(sizeof(struct VariableMap));

    if(new_map == NULL) {
        printf("From: insert_variable(), Error: Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
}
