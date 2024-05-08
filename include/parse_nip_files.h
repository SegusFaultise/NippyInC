#ifndef _PARSE_NIP_FILES_
#define _PARSE_NIP_FILES_

struct FileData {
    char *file_buffer;
    long file_size;
};

char *read_in_nip_file(char *file_path, struct FileData *file_data);

#endif
