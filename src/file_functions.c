#include <stdio.h>
#include <malloc.h>
#include <string.h>

void print_file(char *file_lines, char file_path[]) {
    printf("< %s >\n", file_path);
    printf("-------------\n");
    printf("%s", file_lines);
    printf("-------------\n");
}

char *remove_spaces(char *str){
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    
    return str;
}

char *file_reader(char file_path[]) {
    int buffer_size = 200;
    FILE *fp = fopen(file_path, "r");

    if (fp == NULL) {
        printf("Error, file is NULL");
        return NULL;
    }
    char *file_lines = malloc(buffer_size * sizeof(char));

    if (file_lines == NULL) {
        perror("Memory allocation error");
        fclose(fp);
        return NULL;
    }
    size_t total_size = 0;
    char *line;

    while((line = fgets(file_lines + total_size, buffer_size - total_size, fp)) != NULL) {
        total_size += strlen(line);

        if (total_size + buffer_size > buffer_size) {
            buffer_size *= 2;
            file_lines = realloc(file_lines, buffer_size);

            if (file_lines == NULL) {
                perror("Memory reallocation error");
                fclose(fp);
                free(file_lines);

                return NULL;
            }
        }
    }
    fclose(fp);

    char *mod_file_lines = remove_spaces(file_lines);
    
    print_file(mod_file_lines, file_path);

    return mod_file_lines;

    free(mod_file_lines);
}
