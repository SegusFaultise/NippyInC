#include <stdio.h>

void primary_color() {
    printf("\033[1;33m");
}

void tree_color() {
    printf("\033[1;32m");
}

void error_color() {
    printf("\033[1;31m");
}

void secondary_color() {
    printf("\033[1;35m");
}

void reset_color() {
    printf("\033[0m");
}
