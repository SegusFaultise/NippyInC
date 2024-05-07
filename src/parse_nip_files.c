#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

struct FileData {
    char *file_buffer;
};

char *read_in_nip_file(char *file_path) {
    struct FileData file_data;

    int file_descriptor = open(file_path, O_RDONLY);
    int nb_read = -1;

    file_data.file_buffer = (char*)malloc(sizeof(file_descriptor));

    char *file_contents;

    if(file_descriptor == -1) {
        printf("Error cannot find .nip file! %d", file_descriptor);
        exit(1);
    }

    while(nb_read != 0) {
        nb_read = read(file_descriptor, file_data.file_buffer, 100); 

        if(nb_read == -1) {
            printf("Error cannot read in .nip file %d", nb_read);
            exit(1);
        }
    
        file_data.file_buffer[nb_read] = '\0';
        break;
    }
    close(file_descriptor);

    return file_data.file_buffer;
}
