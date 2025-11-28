#include <stdio.h>
#include <stdbool.h>
#include "opcode.h"
#include "virtual_machine.h"
#include "trap_routine.h"

// Decode instruction table
InstructionDecoder dispatch_instruction_decoder[] = {
	decode_nop, // NOP
	decode_halt, // HALT
	decode_trap, // TRAP
	decode_load, // LOAD
	decode_store, // STORE
	decode_push, // PUSH
	decode_pop, // POP
	decode_dup, // DUP
	decode_add, // ADD
	decode_sub, // SUB
	decode_mul, // MUL
	decode_div, // DIV
	decode_mod, // MOD
	decode_and, // AND
	decode_or, // OR
	decode_xor, // XOR
	decode_not, // NOT
	decode_lt, // LT
	decode_gt, // GT
	decode_eq, // EQ
	decode_jmp, // JMP
	decode_jz, // JZ
	decode_jnz, // JNZ
	decode_call, // CALL
	decode_ret,  // RET
};

// Handle instruction table
InstructionHandler dispatch_instruction_handler[] = {
	handle_nop, // NOP
	handle_halt, // HALT
	handle_trap, // TRAP
	handle_load, // LOAD
	handle_store, // STORE
	handle_push, // PUSH
	handle_pop, // POP
	handle_dup, // DUP
	handle_add, // ADD
	handle_sub, // SUB
	handle_mul, // MUL
	handle_div, // DIV
	handle_mod, // MOD
	handle_and, // AND
	handle_or, // OR
	handle_xor, // XOR
	handle_not, // NOT
	handle_lt, // LT
	handle_gt, // GT
	handle_eq, // EQ
	handle_jmp, // JMP
	handle_jz, // JZ
	handle_jnz, // JNZ
	handle_call, // CALL
	handle_ret,  // RET
};

// Each decoder extracts operands as needed and returns an Instruction struct
Instruction decode_nop(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x03 
	// OPERAND 00 00
	// NOP has no operand
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_halt(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x01 
	// OPERAND 00 00
	// HALT has no operand
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_trap(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x02 
	// OPERAND XX XX
	// TRAP
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_load(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x03 
	// OPERAND XX XX
	// LOAD 
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_store(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x04 
	// OPERAND XX XX
	// STORE
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_push(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x05 
	// OPERAND XX XX
	// PUSH uses a 2-byte operand (value)
	int byte1 = vm->program_memory[vm->pc++];
	int byte2 = vm->program_memory[vm->pc++];
	uint16_t operand = (uint16_t)(byte1 << 8) | byte2;
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = operand;
	return instr;
}

Instruction decode_pop(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x06 
	// OPERAND 00 00
	// POP has no operand
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_dup(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x07 
	// OPERAND 00 00
	// DUP has no operand
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_add(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x08 
	// OPERAND 00 00
	// ADD
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_sub(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x09 
	// OPERAND 00 00
	// SUB
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_mul(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0A 
	// OPERAND 00 00
	// MUL
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_div(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0B 
	// OPERAND 00 00
	// DIV
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_mod(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0C 
	// OPERAND 00 00
	// MOD
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_and(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0D 
	// OPERAND 00 00
	// AND
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_or(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0E 
	// OPERAND 00 00
	// OR
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_xor(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x0F 
	// OPERAND 00 00
	// XOR
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_not(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x10 
	// OPERAND 00 00
	// NOT
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_lt(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x11 
	// OPERAND 00 00
	// LT
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_gt(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x12 
	// OPERAND 00 00
	// GT
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_eq(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x13 
	// OPERAND 00 00
	// EQ
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_jmp(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x14 
	// OPERAND 00 00
	// JMP
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_jz(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x15 
	// OPERAND 00 00
	// JZ
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_jnz(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x16 
	// OPERAND 00 00
	// JNZ
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_call(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x17 
	// OPERAND 00 00
	// CALL
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

Instruction decode_ret(VirtualMachine* vm, uint8_t opcode) {
	// OPCODE  0x18 
	// OPERAND 00 00
	// RET 
	Instruction instr;
	instr.opcode = opcode;
	instr.operand = 0;
	return instr;
}

// Each handler implements the logic for its corresponding instruction
void handle_nop(VirtualMachine* vm, Instruction instruction) {
	// No operation, do nothing
}

void handle_halt(VirtualMachine* vm, Instruction instruction) {
	vm->sys_registers[0] = 1; // Set HALT flag
}

void handle_trap(VirtualMachine* vm, Instruction instruction) {
	uint16_t trap_number = vm->stack[--vm->sp];
	dispatch_trap_handler[trap_number](vm);
}

void handle_load(VirtualMachine* vm, Instruction instruction) {
	uint16_t address = vm->stack[--vm->sp];
	vm->stack[vm->sp++] = vm->data_memory[address];
}

void handle_store(VirtualMachine* vm, Instruction instruction) {
	// address is 16 bits on top of stack
	// data to store is next 16 bits on stack
	// so we pop twice
	// first pop gives us address
	// second pop gives us value
	// memory is byte-addressable, so we store value at data_memory[address]
	// Note: we assume value is 16 bits, so we store it in two consecutive bytes
	uint16_t address = vm->stack[--vm->sp];
	uint16_t value = vm->stack[--vm->sp];
	uint8_t high = (value >> 8) & 0xFF;
	uint8_t low = (value & 0xFF);
	vm->data_memory[address] = high;
	vm->data_memory[address + 1] = low;
}

void handle_push(VirtualMachine* vm, Instruction instruction) {
	vm->stack[vm->sp++] = instruction.operand;
}

void handle_pop(VirtualMachine* vm, Instruction instruction) {
	vm->sp--;
}

void handle_dup(VirtualMachine* vm, Instruction instruction) {
	uint16_t top = vm->stack[vm->sp - 1];
	vm->stack[vm->sp++] = top;
}

void handle_add(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b + a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_sub(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b - a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_mul(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b * a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_div(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b / a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_mod(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b % a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_and(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b & a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_or(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int16_t result = b | a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_xor(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	int_fast16_t result = b ^ a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_not(VirtualMachine* vm, Instruction instruction) {
	int16_t a = vm->stack[--vm->sp];
	int16_t result = ~a;
	vm->stack[vm->sp++] = result;

	// Handle zero flag
	set_flag(vm, result);
}

void handle_lt(VirtualMachine* vm, Instruction instruction) {
	// top < top - 1
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	vm->stack[vm->sp++] = a < b;
}

void handle_gt(VirtualMachine* vm, Instruction instruction) {
	// top > top - 1
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	vm->stack[vm->sp++] = a > b;
}

void handle_eq(VirtualMachine* vm, Instruction instruction) {
	// top == top - 1
	int16_t a = vm->stack[--vm->sp];
	int16_t b = vm->stack[--vm->sp];
	vm->stack[vm->sp++] = a == b;
}

void handle_jmp(VirtualMachine* vm, Instruction instruction) {
	vm->pc = vm->stack[--vm->sp];
}

void handle_jz(VirtualMachine* vm, Instruction instruction) {
	bool zero_flag = vm->sys_registers[1];
	if (zero_flag) {
		vm->pc = vm->stack[--vm->sp];
	}
	else {
		// Just pop the address without jumping
		vm->sp--;
	}
}

void handle_jnz(VirtualMachine* vm, Instruction instruction) {
	bool zero_flag = vm->sys_registers[1];
	if (!zero_flag) {
		vm->pc = vm->stack[--vm->sp];
	}
	else {
		// Just pop the address without jumping
		vm->sp--;
	}
}

void handle_call(VirtualMachine* vm, Instruction instruction) {
	vm->call_stack[vm->csp++] = vm->pc;
	vm->pc = vm->stack[--vm->sp];
}

void handle_ret(VirtualMachine* vm, Instruction instruction) {
	vm->pc = vm->call_stack[--vm->csp];
}

// Helper functions
void set_flag(VirtualMachine* vm, uint16_t result) {
	if (result == 0) {
		vm->sys_registers[1] = 1;
	}
	else {
		vm->sys_registers[1] = 0;
	}
}

uint16_t sign_int(uint16_t value) {
	if (value >> (sizeof(uint16_t) * 8 - 1) == 1) {
		value = value ^ 0xFFFF;
		value += 1;
	}

	return value;
}
