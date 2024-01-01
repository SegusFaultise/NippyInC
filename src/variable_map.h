#ifdef VARIABLE_H
#define VARIABLE_H

struct VariableMap {
    char *variable_name;
    int variable_value_int;

    struct VariableMap[];
}

#endif
