#ifndef LOCAL_H
#define LOCAL_H

#include <stdint.h>

#define MEM_SIZE 0x10000

// lexer.c
uint32_t *lex_file(char *filename, int *token_count);

// emul.c
void start_emul(uint32_t *tokens, int token_count, uint32_t *memory);

#endif
