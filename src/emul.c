#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "local.h"
#include "tools.h"


#define ITN_DIS 0x00     // display R(1)
#define ITN_SET 0x01     // R(1) = (2)
#define ITN_CPY 0x02     // R(1) = R(2)
#define ITN_TRC 0x03     // R(R(1)) = R(R(2))
#define ITN_ADD 0x04     // R(1) = R(1) + R(2)
#define ITN_SUB 0x05     // R(1) = R(1) - R(2)
#define ITN_MUL 0x06     // R(1) = R(1) * R(2)
#define ITN_DIV 0x07     // R(1) = R(1) / R(2)
#define ITN_AND 0x08     // R(1) = R(1) & R(2)
#define ITN_HOR 0x09     // R(1) = R(1) | R(2)
#define ITN_NOT 0x0A     // R(1) = !R(1)
#define ITN_SUP 0x0B     // R(1) = R(1) > R(2)
#define ITN_EQU 0x0C     // R(1) = R(1) == R(2)
#define ITN_JMP 0x0D     // CT = R(1)
#define ITN_GIF 0x0E     // if R(1) != 0 then CT = R(2)
#define ITN_SCT 0x0F     // R(1) = CT
#define ITN_HLT 0x10     // exit

int g_warn;

typedef struct {
    uint32_t **tokens;
    int *token_count;
    int *ct;
    uint32_t **memory;
    int max_stack_size;
} emul_pass_t;

void full_debug(emul_pass_t *st);

// Set Register
void SR(emul_pass_t *st, int index, int value) {    
    if (index < st->max_stack_size) {
        (*st->memory)[index] = value;
    } else if (g_warn) {
        printf("Error: memory index %d out of bounds!\n", index);
        full_debug(st);
    }
}

// Get Register
int GR(emul_pass_t *st, int index) {    
    if (index < st->max_stack_size) {
        return (*st->memory)[index];
    } else if (g_warn) {
        printf("Error: memory index %d out of bounds!\n", index);
        full_debug(st);
    }
    return 0;
}

// Get Token
uint32_t GT(emul_pass_t *st, int to_add) {
    if (*st->ct + to_add < *st->token_count) {
        return (*st->tokens)[*st->ct + to_add];
    } else if (g_warn) {
        printf("Error: token index %d out of bounds!\n", *st->ct + to_add);
        full_debug(st);
    }
    return 0;
}

void full_debug(emul_pass_t *st) {
    g_warn = 0;
    printf("stack size:     0x%x\n", st->max_stack_size);
    printf("CT (index):     %d\n", *st->ct);
    printf("CT (value):     %d\n", GT(st, 0));
    printf("token count:    %d\n", *st->token_count);

}

void start_emul(uint32_t *tokens, int token_count, uint32_t *memory) {
    UNUSED(token_count);

    int ct, itn;
    ct = 0;
    g_warn = 1;

    emul_pass_t *st = malloc(sizeof(emul_pass_t));
    st->tokens = &tokens;
    st->token_count = &token_count;
    st->ct = &ct;
    st->memory = &memory;
    st->max_stack_size = MEM_SIZE;

    printf("Starting emulation...\n\n");

    itn = GT(st, 0);

    do {
        if (itn == ITN_DIS) {
            printf("program: %d\n", GR(st, GT(st, 1)));
            ct += 2;
        } else if (itn == ITN_SET) {
            SR(st, GT(st, 1), GT(st, 2));
            ct += 3;
        } else if (itn == ITN_CPY) {
            SR(st, GT(st, 1), GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_TRC) {
            SR(st, GR(st, GT(st, 1)), GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_ADD) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) + GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_SUB) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) - GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_MUL) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) * GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_DIV) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) / GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_AND) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) & GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_HOR) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) | GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_NOT) {
            SR(st, GT(st, 1), !GR(st, GT(st, 1)));
            ct += 2;
        } else if (itn == ITN_SUP) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) > GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_EQU) {
            SR(st, GT(st, 1), GR(st, GT(st, 1)) == GR(st, GT(st, 2)));
            ct += 3;
        } else if (itn == ITN_JMP) {
            ct = GR(st, GT(st, 1));
        } else if (itn == ITN_GIF) {
            if (GR(st, GT(st, 1))) {
                ct = GR(st, GT(st, 2));
            } else {
                ct += 3;
            }
        } else if (itn == ITN_SCT) {
            SR(st, GT(st, 1), ct);
            ct += 2;
        } else {
            printf("ERROR: Unknown instruction: %d at T%d\n", itn, ct);
            return;
        }
        itn = GT(st, 0);
    } while (itn != ITN_HLT && g_warn);
    if (g_warn) {
        printf("\nEmulation halted at T%d\n", ct);
    } else {
        printf("\nEmulation halted due to error\n");
    }
    free(st);
}
