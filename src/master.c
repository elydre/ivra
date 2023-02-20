#include <stdlib.h>
#include <profan.h>
#include <string.h>
#include <stdio.h>
#include <type.h>

#include "local.h"
#include "tools.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("$BUsage: ivra <file>\n");
        return 0;
    }
    
    char *file = malloc(strlen(argv[1]) + strlen(argv[2]) + 2);
    assemble_path(argv[1], argv[2], file);

    int token_count;

    uint32_t *tokens = lex_file(file, &token_count);

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
    free(file);
    free(mem);

    return 0;
}
