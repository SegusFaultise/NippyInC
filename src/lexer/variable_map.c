#include <stdio.h>
#include <string.h>

#include "variable_map.h"
#include "../color_print_lib/color_print.h"

void initialize_variable_map(struct VariableMap variable_map[]) {
    for(int i = 0; i < MAP_SIZE ; i++) {
        strcpy(variable_map[i].variable_name, "");

        variable_map[i].variable_value_int = 0;
    }
}

char *get_variable_value_by_name(struct VariableMap variable_map[], const char *variable_name_target) {
    for(int i = 0; i < MAP_SIZE; i++) {
        int match = strcmp(variable_map[i].variable_name, variable_name_target);

        //if(match != 0) break; 

        while(match == 0 && strlen(variable_map[i].variable_name) > 0) {
            (void)printf("[FOUND]: %s [VALUE]: %d\n", variable_map[i].variable_name, variable_map[i].variable_value_int);

            return variable_map[i].variable_name;
        }
    }
    return NULL;
}

int insert_variable(struct VariableMap variable_map[], const char *variable_name, int variable_value_int) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if(strcmp(variable_map[i].variable_name, variable_name) && strlen(variable_name) >= 0) {
            strcpy(variable_map[i].variable_name, variable_name);
            variable_map[i].variable_value_int = variable_value_int;

            return variable_map[i].variable_value_int;
        }
        else {
            break;
        }
    }
    return 0;
}

void print_variable_map(struct VariableMap variable_map[]) {
    for(int i = 0; i < MAP_SIZE && strcmp(variable_map[i].variable_name, "") != 0; i++) {
        primary_color();
        printf("[VARIABLE_NAME]: ");
        reset_color();

        secondary_color();
        printf("%s, ", variable_map[i].variable_name);
        reset_color();

        primary_color();
        printf("[VARIABLE_VALUE]: ");
        reset_color();

        secondary_color();
        printf("%d", variable_map[i].variable_value_int);
        reset_color();

        printf("\n");
    }
}
