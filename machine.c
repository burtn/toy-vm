#pragma once
struct VM {
		int stack[256];
		unsigned char sp;
		int r[16];
		unsigned int ip;
		int instruction[65536];
	};

extern struct VM machine;
