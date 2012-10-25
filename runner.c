#pragma once
#include "spec.h"
#include "operations.c"

float temp;

int run(void) {
	while(machine.ip >! INSTRUCTIONS) {
		switch (machine.instruction[machine.ip]) {
			case SKP:
				machine.ip++;
                                    break;
			case HLT:
				return 0;
                                    break;
			case PRT:
				print();
                                    break;
			case ADD:
				add(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
                                    break;
			case SUB:
				sub(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
                                    break;
			case MUL:
				mul(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
                                    break;
			case DIV:
				div(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				machine.ip = machine.ip + 2;
                                    break;
			case POP:
				temp = pop();
                                     break;
			case PSH:
				push(machine.instruction[machine.ip++]);
				machine.ip++;
                                    break;
			case R2S:
				register_to_stack(machine.instruction[machine.ip++]);
				machine.ip++;
                                    break;
			case S2R:
				stack_to_register(machine.instruction[machine.ip++]);
				machine.ip++;
                                    break;
			case SET:
				set(machine.instruction[machine.ip++], machine.instruction[machine.ip +2]);
				// machine.ip = machine.ip + 2;
				machine.ip++;
                                    break;
			default:
				return 1;
		}
		machine.ip++;
	};
	return 0;
};

extern int run(void);
