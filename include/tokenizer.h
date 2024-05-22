#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>

enum TokenDebug {
    DEBUG_ON,
    DEBUG_OFF
};

void build_token_stream(char *raw_file_string, size_t raw_file_string_size, enum TokenDebug token_debug_arg);

#endif
