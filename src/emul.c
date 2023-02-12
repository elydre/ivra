#include <stdint.h>
#include <stdio.h>

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
#define ITN_NOT 0x0A     // R(1) = ~R(1)
#define ITN_SUP 0x0B     // R(1) = R(1) > R(2)
#define ITN_EQU 0x0C     // R(1) = R(1) == R(2)
#define ITN_JMP 0x0D     // CT = R(1)
#define ITN_GIF 0x0E     // if R(1) != 0 then CT = R(2)
#define ITN_SCT 0x0F     // R(1) = CT
#define ITN_HLT 0x10    // exit


void start_emul(uint32_t *tokens, int token_count, uint32_t *memory) {
    UNUSED(token_count);

    int current_token = 0;

    printf("Starting emulation...\n\n");

    while (tokens[current_token] != ITN_HLT) {  
        if (tokens[current_token] == ITN_DIS) {
            printf("program: %d\n", memory[tokens[current_token + 1]]);
            current_token += 2;
        } else if (tokens[current_token] == ITN_SET) {
            memory[tokens[current_token + 1]] = tokens[current_token + 2];
            current_token += 3;
        } else if (tokens[current_token] == ITN_CPY) {
            memory[tokens[current_token + 1]] = memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_TRC) {
            memory[memory[tokens[current_token + 1]]] = memory[memory[tokens[current_token + 2]]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_ADD) {
            memory[tokens[current_token + 1]] += memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_SUB) {
            memory[tokens[current_token + 1]] -= memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_MUL) {
            memory[tokens[current_token + 1]] *= memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_DIV) {
            memory[tokens[current_token + 1]] /= memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_AND) {
            memory[tokens[current_token + 1]] &= memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_HOR) {
            memory[tokens[current_token + 1]] |= memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_NOT) {
            memory[tokens[current_token + 1]] = ~memory[tokens[current_token + 1]];
            current_token += 2;
        } else if (tokens[current_token] == ITN_SUP) {
            memory[tokens[current_token + 1]] = memory[tokens[current_token + 1]] > memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_EQU) {
            memory[tokens[current_token + 1]] = memory[tokens[current_token + 1]] == memory[tokens[current_token + 2]];
            current_token += 3;
        } else if (tokens[current_token] == ITN_JMP) {
            current_token = memory[tokens[current_token + 1]];
        } else if (tokens[current_token] == ITN_GIF) {
            if (memory[tokens[current_token + 1]] != 0) {
                current_token = memory[tokens[current_token + 2]];
            } else {
                current_token += 3;
            }
        } else if (tokens[current_token] == ITN_SCT) {
            memory[tokens[current_token + 1]] = current_token;
            current_token += 2;
        } else {
            printf("Unknown instruction: %d at %d\n", tokens[current_token], current_token);
            return;
        }
    }
    printf("\nEmulation halted at T%d\n", current_token);
}
