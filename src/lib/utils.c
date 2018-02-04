#include "utils.h"
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>

int chartoi(char c) {
	int i = c - '0';
	return i;
}

// TODO
// refactor so it takes a free'd space and writes the 2d array into it
// could also be a struct to hold array length info as well
// that way it could be kinda variable length
//
// WARNING: the code in current state doesn't quite work, needs the above refactor!
char *linesplit(char *input) {
		//flag to mark end of input
		int eoi = 0;

		// array to hold lines
		static char *result[50][50];

		// length of result
		int reslen = 0;

		do{
			// array of current line is result[reslen]

        	// array of characters in current number
        	char current[10];

        	// counter for length of current number
        	int curlen = 0;

        	// counter for length of current line
        	int linelen = 0;

        	// flag to mark if end of line is reached
        	int eol = 0;

        	do {
            	// check if pointing to a character
            	if (!isspace(*input)) {
					printf("current: %c\n", *input);
                	// add character to current word
                	current[curlen] = *input;
                	// increment length
                	curlen++;
            	}

            	// increment pointer
				input++;

            	if (isspace(*input) || *input == 10 || *input == '\0') {
                	// mark end of line reached
                	if (*input == 10 || *input == '\0') {
                    	eol = 1;
                	}

                	// null-terminate current character
                	current[curlen] = '\0';
                	// convert current num to int, append to line array
                	result[reslen][linelen] = current;
                	// increment line length
                	linelen++;

                	// reset current char
                	curlen = 0;
                	current[0] = '\0';
            	}

        	}
			while (!eol);
			
			if (*input == '\0') {
				eoi = 1;
			}

			reslen++;

		}
		while (!eoi);

		return **result;
}

