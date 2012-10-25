toy-vm
======

The Beginnings of a Toy VM
<hr>
### Status
![Build Status](https://travis-ci.org/jake5991/toy-vm.png)
### Compiling
You'll need a [Compiler that supports #pragme once](http://en.wikipedia.org/wiki/Pragma_once#Portability) otherwise you'll have to add include guards yourself.

If your using gcc:
```sh
gcc ./vm.c -o vm
./vm ./bytes.i
```
Or if you plan on using gdb:
```sh
gcc -g ./vm.c -o vm
./vm ./bytes.i
```
### About
This is a toy VM, the machine is effectively implemented as a struct:
```C
struct VM {
  	int stack[256];
		unsigned char sp;
		int r[15];
		unsigned short ip;
		int instruction[65536];
	};

extern struct VM machine;
```

Or rather

+ It has a stack
+ a stack pointer
+ some registers
+ an instruction pointer
+ an instruction buffer (the part that is executed)

A word on registers, this is designed to be a register based but only r0 has a special purpose - r0 holds the answer to the previous operation whilst r1-15 Are general purpose registers.

The instruction buffer can (currently) grow as large as 65536 as defined in the spec (spec.h):
```C
#define INSTRUCTIONS  65536
```

The VM supports the instruction set also defined in the spec:
```
#define SKP 0  /* Skip to the next instruction                          */
#define PSH 1  /* PUSH <n>: push <n> to Top of Stack.                 */
#define POP 2  /* POP: pop Top of stack.       */
#define R2S 3  /* Put register on top of stack */                      
#define S2R 4  /* PLACE <r>: store TOS to register <r>
                         and pop the stack.              
                                      */

#define JMP 5  /* JMP <i>: go to instruction <i>.            */
#define JZ  6  /* JZ <i>: if TOS is zero,
                         pop TOS and go to instruction <i>;
                         else just pop TOS.                         */
#define JNZ 7  /* JNZ <i>: if TOS is nonzero,
                         pop TOS and go to instruction <i>;
                         else just pop TOS.                         */
#define ADD 8  /* ADD: r1 + r2 -> r0                     */
#define SUB 9  /* SUB: r1 - r2 -> r0                        */
#define MUL 10  /* MUL: r1 * r2 -> r0                        */
#define DIV 11  /* DIV: r1 / r2 -> r0                        */
#define PRT 12  /* PRINT: print r0 to STDOUT.    */
#define HLT 13  /* exit the VM                   */
#define SET 14  /* set register value                 */
```

### LICENCE
Copyright (c) 2012 Jake Burton

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
