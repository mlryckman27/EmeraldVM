#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "virtual_machine.h"

typedef enum {
	DEBUG_FLAG,
	WRITE_NUM,
	READ_NUM,
	WRITE_CHAR,
	READ_CHAR,
	WRITE_STRING,
	READ_STRING,

} TrapCode;

typedef void (*TrapHandler)(VirtualMachine* vm);
void handle_debug_flag(VirtualMachine* vm);
void handle_write_num(VirtualMachine* vm);
void handle_read_num(VirtualMachine* vm);
void handle_write_char(VirtualMachine* vm);
void handle_read_char(VirtualMachine* vm);
void handle_write_string(VirtualMachine* vm);
void handle_read_string(VirtualMachine* vm);

extern TrapHandler dispatch_trap_handler[];