#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>

enum TokenType {
    MULTIPLY,
    DIVIDE,
    ADDITION,
    MINUS
};

struct Token {
    char token_value;
    char token_type;
};

char *tokenizer() {
     
    return "oo";
}

char *file_reader(char file_path[]) { 
    unsigned long buffer = 255;
    char *file_lines = malloc(buffer);

    FILE *fp = fopen(file_path, "r");

    if(fp == NULL) {
        printf("Error, file is NULL");

        return NULL;
    }
    while(fgets(file_lines, buffer, fp)) {
        printf("%s", file_lines);
    }
    
    fclose(fp);

    return file_path;
}

int main() {
    printf("main 0/n \n");

    file_reader("../main.nip");

    return 0;
}
