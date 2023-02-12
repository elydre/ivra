#ifndef LOCAL_H
#define LOCAL_H

#define UNUSED(x) (void)(x)

#include <stdint.h>

// lexer.c4
uint32_t *lex_file(char *filename, int *token_count);

#endif
