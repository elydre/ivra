#include <syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <type.h>

uint32_t *lex_string(char *program, int *ptr_token_count) {
    int token_count = 0;
    int token_capacity = 8;
    uint32_t *tokens = malloc(sizeof(uint32_t) * token_capacity);

    char *current = program;
    char tmp[32];
    int tmp_index = 0;
    int tmp_value;

    int in_comment = 0;

    while (*current != '\0') {
        char c = *current;

        if (c == '#') {
            in_comment = !in_comment;
            current++;
            continue;
        }

        if (in_comment) {
            current++;
            continue;
        }

        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            if (tmp_index == 0) {
                current++;
                continue;
            }
            tmp[tmp_index] = '\0';
            tmp_value = atoi(tmp);
            tokens[token_count++] = tmp_value;
            tmp_index = 0;
            if (token_count >= token_capacity) {
                token_capacity *= 2;
                tokens = realloc(tokens, sizeof(uint32_t) * token_capacity);
            }
            current++;
            continue;
        }
        
        tmp[tmp_index++] = c;
        current++;
    }
    *ptr_token_count = token_count;
    return tokens;
}

uint32_t *lex_file(char *file, int *token_count) {
    char *program = NULL;

    if (c_fs_does_path_exists(file) && c_fs_get_sector_type(c_fs_path_to_id(file)) == 2) {
        char *program = c_fs_declare_read_array(file);
        c_fs_read_file(file, (uint8_t *) program);

        uint32_t *tokens = lex_string(program, token_count);

        free(program);
        
        return tokens;
    }

    return NULL;
}
