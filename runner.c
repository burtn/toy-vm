#pragma once
#include "spec.h"
#include "operations.c"

float temp;

int run(void) {
	while(machine.ip < INSTRUCTIONS) {
		switch (machine.instruction[machine.ip]) {
			case SKP:
				machine.ip++;
			case HLT:
				return 0;
			case PRT:
				print();
			case ADD:
				add(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
			case SUB:
				sub(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
			case MUL:
				mul(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
			case DIV:
				div(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
			case POP:
				temp = pop();
			case PSH:
				push(machine.instruction[machine.ip++]);
				machine.ip++;
			case R2S:
				register_to_stack(machine.instruction[machine.ip++]);
				machine.ip++;
			case S2R:
				stack_to_register(machine.instruction[machine.ip++]);
				machine.ip++;
			case SET:
				set(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
			default:
				return 1;
		}
		machine.ip++;
	};
	return 0;
};

extern int run(void);
