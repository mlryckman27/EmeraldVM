/* Pseudocode plan:
 - Define ANSI blue and reset escape sequences.
 - In debug(), when iterating program memory, print each byte wrapped with blue color code.
 - Preserve existing formatting and behavior; cast to unsigned for printf.
 - Keep other functions unchanged.
*/

#include <stdlib.h>
#include <stdio.h>
#include "virtual_machine.h"
#include "opcode.h"

// Functions for handling virtual machine resources
void initialize_vm(VirtualMachine* vm) {
	vm->program_memory = calloc(PROGRAM_MEMORY_SIZE, sizeof(uint8_t));  // calloc allocates memory and initializes each byte to 0
	vm->data_memory = calloc(DATA_MEMORY_SIZE, sizeof(uint8_t));
	vm->stack = calloc(STACK_SIZE, sizeof(uint16_t));
	vm->call_stack = calloc(CALL_STACK_SIZE, sizeof(uint16_t));
	vm->sys_registers = calloc(SYS_REGISTERS_SIZE, sizeof(uint8_t)); // calloc ensures HALT flag and zero flag start as 0
	vm->pc = 0;
	vm->sp = 0;
	vm->csp = 0;
	vm->program_size = 0;
}

void load_program(VirtualMachine* vm, const uint8_t* program, size_t program_size) {
	for (size_t i = 0; i < program_size && i < PROGRAM_MEMORY_SIZE; i++) {
		vm->program_memory[i] = program[i];
	}

	vm->program_size = program_size;
}

void run_vm(VirtualMachine* vm) {
	while (vm->sys_registers[0] == 0) { // while HALT flag is not set
		if (vm->sys_registers[2] == 1) {
			debug(vm);
		}

		uint8_t opcode = fetch(vm);
		Instruction instruction = decode(vm, opcode);
		execute(vm, instruction);
	}

	cleanup_vm(vm);
}

void cleanup_vm(VirtualMachine* vm) {
	free(vm->program_memory);
	free(vm->data_memory);
	free(vm->stack);
	free(vm->call_stack);
	free(vm->sys_registers);
}

// Fetch-decode-execute cycle functions
uint8_t fetch(VirtualMachine* vm) {
	return vm->program_memory[vm->pc++];
}

Instruction decode(VirtualMachine* vm, uint8_t opcode) {
	return dispatch_instruction_decoder[opcode](vm, opcode);
}

void execute(VirtualMachine* vm, Instruction instruction) {
	dispatch_instruction_handler[instruction.opcode](vm, instruction);
}

// Debug functions
void debug(VirtualMachine* vm) {
	const char* BLUE = "\x1b[34m";
	const char* RESET = "\x1b[0m";

	printf("\n--------------------\n");
	printf(" PRG MEM: ");
	for (int i = 0; i < vm->program_size; i++) {
		// print each program memory byte in blue
		if (vm->pc == i) {
			printf(" %s%04x%s%", BLUE, vm->program_memory[i], RESET);
		}
		else {
			printf(" %04x", vm->program_memory[i]);
		}
	}

	//printf("\n");
	//printf("DATA MEM: ");
	//for (int i = 0; i < DATA_MEMORY_SIZE; i++) {
	//	printf(" %04x", vm->data_memory[i]);
	//}

	printf("\n");
	printf("   STACK: ");
	for (int i = 0; i < vm->sp; i++) {
		if (vm->sp > -1) {
			printf(" %04x", vm->stack[i]);
		}
	}

	printf("\n");
	printf("      PC: %02x\n", vm->pc);
	printf("--------------------\n");
}
