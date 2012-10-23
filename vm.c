#include <stdio.h>
#include "spec.h"
#include "operations.c"
#include "machine.c"
#include "runner.c"

struct VM machine;

void init(void) {
    int i;

    machine.sp = 0;

    for (i = 0; i < 256; i++) {
        machine.stack[i] = 0;
    };

    for (i = 0; i < 16; i++) {
        machine.r[i] = 0;
    };

    for (i = 0; i < 65536; i++) {
        machine.instruction[i] = 0;
    };

    machine.ip = 0;
}

void read_bytecode(FILE *fp) {
    int i;
    i=-1;
    char line [ 128 ]; /* or other suitable maximum line size */
    do {
		machine.instruction[i] = atoi(line);
        i++;
      } while ( fgets ( line, sizeof line, fp ) != NULL ); /* read a line */
      
	/*
    do {

        bytes_read = fread(instruction, 1, 1, fp);
        printf("%i\n", fread(instruction, 1, 1, fp));
        instruction++;
    }
    while (bytes_read > 0);
    */
}

int main(int argc, char *argv[]) {

	init();

	if(argc !=2) {
		/* The VM must have a bytecode file to execute! */
		printf("You must specify a bytecode file, e.g %s /path/to/file.i\n", argv[0]);
		return 0;
	};

	FILE *bytecode = fopen( argv[1], "r" );

        /* if fopen is 0 the file could not be opened! */
        if ( bytecode == 0 ) {
            printf("Could not read %s \n", argv[1]);
        } else {
	    read_bytecode(bytecode);
	    fclose(bytecode);
	    int status = run();
	    if (status == 1) {
			printf("STOP: A Fatal Error Occured whilst attempting to execute instruction buffer!\n");
			int i;
			for(i=0; i<10; i++) {
				printf("%d\n", machine.instruction[i]);
			};
			return 1;
	    } else {
			return 0;
	    };

        };
	return 0;
};
