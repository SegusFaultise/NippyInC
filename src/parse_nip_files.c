#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "../include/parse_nip_files.h"

long get_file_size(char *filename) {
    struct stat file_status;

    if (stat(filename, &file_status) < 0) {
        return -1;
    }

    return file_status.st_size;
}

char *read_in_nip_file(char *file_path) {
    int file_descriptor = open(file_path, O_RDONLY);
    int nb_read = -1;

    long file_size = get_file_size(file_path);

    char *file_buffer = (char*)malloc(file_size);

    if(file_descriptor == -1) {
        printf("Error cannot find .nip file! %d", file_descriptor);
        exit(1);
    }

    if(nb_read != 0) {
        nb_read = read(file_descriptor, file_buffer, file_size); 

        if(nb_read == -1) {
            free(file_buffer);
            printf("Error cannot read in .nip file %d", nb_read);
            exit(1);
        }
    }
    close(file_descriptor);

    return file_buffer;
}
