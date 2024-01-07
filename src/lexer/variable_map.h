#ifndef VARIABLE_MAP_H
#define VARIABLE_MAP_H

#define MAP_SIZE 255

struct VariableMap {
    char variable_name[MAP_SIZE];
    int variable_value_int;
};

void initialize_variable_map(struct VariableMap variable_map[]);

int insert_variable(struct VariableMap variable_map[], const char *variable_name, int variable_value_int);

void print_variable_map(struct VariableMap variable_map[]);

#endif
