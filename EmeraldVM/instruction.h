#pragma once
#include <stdint.h>

typedef struct {
    uint8_t opcode;
    uint16_t operand;
} Instruction;
