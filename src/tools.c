#include <stdint.h>
#include <stdio.h>

#include "tools.h"

void print_lexer_output(uint32_t *tokens, int token_count) {
    printf("Token count: %d\nprogram: ", token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%d ", tokens[i]);
    }
    printf("\n");
}