#pragma once

#include "virtual_machine.h"

// Opcode enum
typedef enum {
	// System Instructions
	NOP = 0,
	HALT,
	TRAP,

	// Data Instructions
	LOAD,
	STORE,

	// Stack Instructions
	PUSH,
	POP,
	DUP,

	// Arithmetic and Logic Instructions
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	AND,
	OR,
	XOR,
	NOT,

	// Control Flow Instructions
	LT,
	GT,
	EQ,
	JMP,
	JZ,
	JNZ,
	CALL,
	RET,
} Opcode;

// Decode instruction table
typedef Instruction(*InstructionDecoder)(VirtualMachine* vm, uint8_t opcode);
Instruction decode_nop(VirtualMachine* vm, uint8_t opcode);
Instruction decode_halt(VirtualMachine* vm, uint8_t opcode);
Instruction decode_trap(VirtualMachine* vm, uint8_t opcode);
Instruction decode_load(VirtualMachine* vm, uint8_t opcode);
Instruction decode_store(VirtualMachine* vm, uint8_t opcode);
Instruction decode_push(VirtualMachine* vm, uint8_t opcode);
Instruction decode_pop(VirtualMachine* vm, uint8_t opcode);
Instruction decode_dup(VirtualMachine* vm, uint8_t opcode);
Instruction decode_add(VirtualMachine* vm, uint8_t opcode);
Instruction decode_sub(VirtualMachine* vm, uint8_t opcode);
Instruction decode_mul(VirtualMachine* vm, uint8_t opcode);
Instruction decode_div(VirtualMachine* vm, uint8_t opcode);
Instruction decode_mod(VirtualMachine* vm, uint8_t opcode);
Instruction decode_and(VirtualMachine* vm, uint8_t opcode);
Instruction decode_or(VirtualMachine* vm, uint8_t opcode);
Instruction decode_xor(VirtualMachine* vm, uint8_t opcode);
Instruction decode_not(VirtualMachine* vm, uint8_t opcode);
Instruction decode_lt(VirtualMachine* vm, uint8_t opcode);
Instruction decode_gt(VirtualMachine* vm, uint8_t opcode);
Instruction decode_eq(VirtualMachine* vm, uint8_t opcode);
Instruction decode_jmp(VirtualMachine* vm, uint8_t opcode);
Instruction decode_jz(VirtualMachine* vm, uint8_t opcode);
Instruction decode_jnz(VirtualMachine* vm, uint8_t opcode);
Instruction decode_call(VirtualMachine* vm, uint8_t opcode);
Instruction decode_ret(VirtualMachine* vm, uint8_t opcode);

// Handle instruction table
typedef void (*InstructionHandler)(VirtualMachine* vm, Instruction instruction);
void handle_nop(VirtualMachine* vm, Instruction instruction);
void handle_halt(VirtualMachine* vm, Instruction instruction);
void handle_trap(VirtualMachine* vm, Instruction instruction);
void handle_load(VirtualMachine* vm, Instruction instruction);
void handle_store(VirtualMachine* vm, Instruction instruction);
void handle_push(VirtualMachine* vm, Instruction instruction);
void handle_pop(VirtualMachine* vm, Instruction instruction);
void handle_dup(VirtualMachine* vm, Instruction instruction);
void handle_add(VirtualMachine* vm, Instruction instruction);
void handle_sub(VirtualMachine* vm, Instruction instruction);
void handle_mul(VirtualMachine* vm, Instruction instruction);
void handle_div(VirtualMachine* vm, Instruction instruction);
void handle_mod(VirtualMachine* vm, Instruction instruction);
void handle_and(VirtualMachine* vm, Instruction instruction);
void handle_or(VirtualMachine* vm, Instruction instruction);
void handle_xor(VirtualMachine* vm, Instruction instruction);
void handle_not(VirtualMachine* vm, Instruction instruction);
void handle_lt(VirtualMachine* vm, Instruction instruction);
void handle_gt(VirtualMachine* vm, Instruction instruction);
void handle_eq(VirtualMachine* vm, Instruction instruction);
void handle_jmp(VirtualMachine* vm, Instruction instruction);
void handle_jz(VirtualMachine* vm, Instruction instruction);
void handle_jnz(VirtualMachine* vm, Instruction instruction);
void handle_call(VirtualMachine* vm, Instruction instruction);
void handle_ret(VirtualMachine* vm, Instruction instruction);

extern InstructionDecoder dispatch_instruction_decoder[];
extern InstructionHandler dispatch_instruction_handler[];

// Helper functions
uint16_t sign_int(uint16_t value);
void set_flag(VirtualMachine* vm, uint16_t result);
