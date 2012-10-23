#pragma once
struct VM {
		int stack[256];
		unsigned char sp;
		int r[15];
		unsigned short ip;
		int instruction[65536];
	};

extern struct VM machine;
