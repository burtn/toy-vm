#pragma once
/* 
	This file defines the Intruction set for the i VM 
	The i VM is register based (though it has a stack!)
	* The stack may be used more later, for now we only
	* have a massive 13 instructions
	
	There are 16 registers!
	Only r0 has a special purpose:
		r0 holds the answer to the previous operation
		r1-15 Are general purpose registers

*/

#define SKP 13  /* Skip to the next instruction                          */
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
#define HLT 0  /* exit the VM                   */
#define SET 14  /* set register value                 */

/* Support is present for */ #define INSTRUCTIONS  65536 /* instructions. */

