#pragma once
#include "machine.c"


/* SKP is handled in runner.c */
void push(int n) {
	if(machine.sp == 255) {
		for(machine.sp = 0; machine.sp < 256; machine.sp++) {
			machine.stack[machine.sp] = machine.stack[machine.sp + 1];
		}
		machine.sp = 255;
		machine.stack[machine.sp] = n;
	} else {
		machine.stack[machine.sp] = n;
		machine.sp++;
	};
};
float pop(void) {
	machine.sp--;
	float current = machine.stack[machine.sp];
	machine.stack[machine.sp] = 0;
	return current;
};
void register_to_stack(int r) {
	push(machine.r[r]);
};
void stack_to_register(int r) {
	machine.r[r] = pop();
};

void jmp(int n);
void jz(int n);
void jnz(int n);

void add(int r1, int r2) {
	if(r1 < 16 && r2 < 16) {
		machine.r[0] = machine.r[r1] + machine.r[r2];
	} else {
		machine.r[0] = 0;
	};
};
void sub(int r1, int r2) {
	if(r1 < 16 && r2 < 16) {
		machine.r[0] = machine.r[r1] - machine.r[r2];
	} else {
		machine.r[0] = 0;
	};
};
void mul(int r1, int r2) {
	if(r1 < 16 && r2 < 16) {
		machine.r[0] = machine.r[r1] * machine.r[r2];
	} else {
		machine.r[0] = 0;
	};
};
void div(int r1, int r2) {
	if(r1 < 16 && r2 < 16) {
		machine.r[0] = machine.r[r1] / machine.r[r2];
	} else {
		machine.r[0] = 0;
	};
};
void print(void) {
	machine.sp--;
	printf("%d", machine.stack[machine.sp]);
	machine.sp++;
};

void set(int r, int n) {
	machine.r[r] = n;
};
/* HLT is handled in runner.c */
