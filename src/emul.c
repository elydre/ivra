#include <stdint.h>
#include <stdio.h>

#include "tools.h"


#define ITN_DIS 0x0     // display R(1)
#define ITN_SET 0x1     // R(1) = (2)
#define ITN_CPY 0x2     // R(1) = R(2)
#define ITN_TRC 0x3     // R(1) = R(R(2))
#define ITN_ADD 0x4     // R(1) = R(1) + R(2)
#define ITN_SUB 0x5     // R(1) = R(1) - R(2)
#define ITN_MUL 0x6     // R(1) = R(1) * R(2)
#define ITN_DIV 0x7     // R(1) = R(1) / R(2)
#define ITN_AND 0x8     // R(1) = R(1) & R(2)
#define ITN_HOR 0x9     // R(1) = R(1) | R(2)
#define ITN_NOT 0xA     // R(1) = ~R(1)
#define ITN_SUP 0xB     // R(1) = R(1) > R(2)
#define ITN_EQU 0xC     // R(1) = R(1) == R(2)
#define ITN_JMP 0xD     // PC = R(1)
#define ITN_HLT 0xE     // Halt


void start_emul(uint32_t *tokens, int token_count, uint32_t *memory) {
    UNUSED(token_count);

    int current_token = 0;

    printf("Starting emulation...\n");

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
            memory[tokens[current_token + 1]] = memory[memory[tokens[current_token + 2]]];
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
        } else {
            printf("Unknown instruction: %d at %d\n", tokens[current_token], current_token);
            return;
        }
    }
}
