#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "virtual_machine.h"
#include "opcode.h"

int main(int argc, char* argv[]) {
	uint8_t sample_program[] = {
	DBG,
	PUSH, 0x00, 0x0E,  // push 14 onto stack
	CALL,			   // call sub-routine starting at address 0x000E
	PUSH, 0x00, 0x00,
	LOAD,
	PUSH, 0x00, 0x00,
	TRAP,
	HALT,			   // halt the virtual machine

	// function_print_countdown
	PUSH, 0x00, 0x0A,  // push 10 onto the stack
	PUSH, 0x00, 0x00,  // push trap code 0 onto the stack
	TRAP,			   // print top of stack as an integer to the terminal
	PUSH, 0x00, 0x01,  // push 1 onto the stack
	SUB,			   // sub 1 from value on top of stack
	PUSH, 0x00, 0x11,  // push 17 onto stack
	JNZ,			   // if zero-flag is not set, jump to second instruction in the sub-routine (at address 0x0011)
	PUSH, 0x00, 0x00,
	STORE,
	RET				   // ret from sub-routine back to 0x04
	};

	VirtualMachine vm;
	initialize_vm(&vm);
	load_program(&vm, sample_program, sizeof(sample_program));
	run_vm(&vm);

	// prevent console from closing immediately
	printf("\nProgram halted. Press Enter to exit...\n");
	getchar();
	return 0;
}
