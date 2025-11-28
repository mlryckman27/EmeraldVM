#include "trap_routine.h"

TrapHandler dispatch_trap_handler[] = {
	handle_debug_flag,
	handle_write_num,
	handle_read_num,
	handle_write_char,
	handle_read_char,
	handle_write_string,
	handle_read_string,
};

void handle_debug_flag(VirtualMachine* vm) {
	vm->sys_registers[2] = 1;
}

void handle_write_num(VirtualMachine* vm) {
	int16_t value = sign_int(vm->stack[vm->sp - 1]);
	printf("%d", value);
}

void handle_read_num(VirtualMachine* vm) {
	int16_t value;
	scanf_s("%hd", &value);
	vm->stack[vm->sp++] = (uint16_t)value;
}

void handle_write_char(VirtualMachine* vm) {
	char value = (char)(vm->stack[vm->sp - 1]);
	printf("%c", value);
}

void handle_read_char(VirtualMachine* vm) {
	char value;
	scanf_s("%c", &value, sizeof(value));
	vm->stack[vm->sp++] = (uint16_t)value;
}

void handle_write_string(VirtualMachine* vm) {
	// Not implemented
}

void handle_read_string(VirtualMachine* vm) {
	// Not implemented;
}
