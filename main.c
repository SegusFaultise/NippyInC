#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "include/parse_nip_files.h"

#define TEST_FILE_PATH "../main.nip"

void split_token_stream(char *file_contents) {
    for(int i = 0; i < strlen(file_contents); i++) { 
        if(file_contents == NULL) {
            break;
        }

        while(isalpha(file_contents[i])) {
            printf("%c\n", file_contents[i]);

            break;
        }
    }
}

int main(int argc, char **argv) {
    printf("main() HIT!\n\n");

    char *file_contents = read_in_nip_file(TEST_FILE_PATH);

    printf("%s", file_contents);
    
    split_token_stream(file_contents);
    
    return 0;
}
