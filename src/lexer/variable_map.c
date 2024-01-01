#include <stdio.h>
#include <string.h>

#include "variable_map.h"

void initialize_variable_map(struct VariableMap variable_map[]) {
    for(int i = 0; i < MAP_SIZE ; i++) {
        strcpy(variable_map[i].variable_name, "");

        variable_map[i].variable_value_int = 0;
    }
}

void insert_variable(struct VariableMap variable_map[], const char *variable_name, int variable_value_int) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if (strcmp(variable_map[i].variable_name, "") == 0) {
            strcpy(variable_map[i].variable_name, variable_name);
            variable_map[i].variable_value_int = variable_value_int;
            break;  // Break after inserting the variable
        }
    }
}

void print_variable_map(struct VariableMap variable_map[]) {
    for(int i = 0; i < MAP_SIZE && strcmp(variable_map[i].variable_name, "") != 0; i++) {
        printf("Var name: [ %s ], || Var int value: [ %d ]\n", variable_map[i].variable_name, variable_map[i].variable_value_int);
    }
}
