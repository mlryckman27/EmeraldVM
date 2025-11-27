#pragma once

#include <stdint.h>
#include "instruction.h"

// Macros for ISA components
#define PROGRAM_MEMORY_SIZE 256 * 256
#define DATA_MEMORY_SIZE 256 * 256
#define STACK_SIZE 256
#define CALL_STACK_SIZE 256
#define SYS_REGISTERS_SIZE 16

// Virtual machine
typedef struct {
	uint8_t* program_memory; // where the program is loaded
	uint8_t* data_memory; // general-purpose data memory
	uint16_t* stack; // since this is not register-based, we need a stack to store values
	uint16_t* call_stack; // for return addresses
	uint8_t* sys_registers; // first byte is HALT flag, second byte is zero flag, third is debug flag, remaining are for traps
	uint16_t pc; // program counter
	uint16_t sp; // stack pointer
	uint16_t csp; // call stack pointer

	// DEBUG
	uint16_t program_size;
} VirtualMachine;

// Function prototypes
void initialize_vm(VirtualMachine* vm);
void run_vm(VirtualMachine* vm);
void load_program(VirtualMachine* vm, const uint8_t* program, size_t program_size);
void cleanup_vm(VirtualMachine* vm);

// fetch-decode-execute cycle functions

// Fetches the next instruction from memory.  The program counter is incremented.
uint8_t fetch(VirtualMachine* vm);

// Decodes the fetched instruction and returns the operand. Increments the program counter as needed.
Instruction decode(VirtualMachine* vm, uint8_t opcode);

// Executes the instruction with the given opcode and operand.
void execute(VirtualMachine* vm, Instruction instruction);

// Debug
void debug(VirtualMachine* vm);
