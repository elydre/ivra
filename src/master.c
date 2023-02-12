#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "local.h"
#include "tools.h"

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int token_count;

    uint32_t *tokens = lex_file("input.ivr", &token_count);

    if (tokens == NULL) {
        printf("Error during lexing...\n");
        return 1;
    }

    print_lexer_output(tokens, token_count);

    if (token_count == 0) {
        printf("No tokens found...\n");
        return 1;
    }

    uint32_t *mem = calloc(MEM_SIZE, sizeof(uint32_t));

    start_emul(tokens, token_count, mem);

    free(tokens);
    free(mem);

    return 0;
}
