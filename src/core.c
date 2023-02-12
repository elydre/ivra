#include <stdint.h>
#include <stdio.h>

#include "local.h"

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int token_count;

    uint32_t *tokens = lex_file("input.ivr", &token_count);

    printf("Token count: %d\nprogram: ", token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%d ", tokens[i]);
    }
    printf("\n");
    
    return 0;
}
