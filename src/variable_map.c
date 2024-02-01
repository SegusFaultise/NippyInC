#include <stdio.h>
#include <string.h>

#include "../include/variable_map.h"
#include "../lib/color_printf_lib/include/color_print.h"

void initialize_variable_map(struct VariableMap variable_map[]) {
    for(int i = 0; i < MAP_SIZE ; i++) {
        (void)strcpy(variable_map[i].variable_name, "");

        variable_map[i].variable_value_int = 0;
    }
}

char *get_variable_value_by_name(struct VariableMap variable_map[], const char *variable_name_target) {
    for(int i = 0; i < MAP_SIZE; i++) {
        int match = (int)strcmp(variable_map[i].variable_name, variable_name_target);

        //if(match != 0) break; 

        while(match == 0 && (int)strlen(variable_map[i].variable_name) > 0) {
            (void)printf("[FOUND]: %s [VALUE]: %d\n", variable_map[i].variable_name, variable_map[i].variable_value_int);

            return variable_map[i].variable_name;
        }
    }
    return NULL;
}

int insert_variable(struct VariableMap variable_map[], const char *variable_name, int variable_value_int) {
    for(int i = 0; i < MAP_SIZE; i++) {
        if((int)strcmp(variable_map[i].variable_name, variable_name) && (int)strlen(variable_name) >= 0) {
            (void)strcpy(variable_map[i].variable_name, variable_name);

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
    for(int i = 0; i < MAP_SIZE && (int)strcmp(variable_map[i].variable_name, "") != 0; i++) {
        (void)primary_color();
        (void)printf("[VARIABLE_NAME]: ");
        (void)reset_color();

        (void)secondary_color();
        (void)printf("%s, ", variable_map[i].variable_name);
        (void)reset_color();

        (void)primary_color();
        (void)printf("[VARIABLE_VALUE]: ");
        (void)reset_color();

        (void)secondary_color();
        (void)printf("%d", variable_map[i].variable_value_int);
        (void)reset_color();

        (void)printf("\n");
    }
}
