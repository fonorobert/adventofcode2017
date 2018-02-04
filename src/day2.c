// checksum: sum of differences between largest and smallest value on each line
// spreadsheet: entered as command line argument, delimiter is LF (coded 10 in ascii)
// use strtok() to tokenize string input

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib/utils.h"

#define false 0
#define true 1


int main(int argc, char *argv[]) {

	// get argument
	char *input = argv[1];
	
	int checksum = 0;
	
	// flag to mark end of input
	int eoi = false;

	do {
		// array of numbers in current line
		int line[50];

		// array of characters in current number
		char current[10];

		// counter for length of current number
		int curlen = 0;

		// counter for length of current line
		int linelen = 0;

		// flag to mark if end of line is reached
		int eol = false;

		do {
			// check if pointing to a digit
			if (isdigit(*input)) {
				// add character to current number
				current[curlen] = *input;
				// increment length
				curlen++;
			} 

			// increment pointer
			input++;
		
			if (!isdigit(*input)) {
				// mark end of line reached
				if (*input == 10 || *input == '\0') {
					eol = true;
				}
			
				// null-terminate current character
				current[curlen] = '\0';
				// convert current num to int, append to line array
				line[linelen] = atoi(current);
				// increment line length
				linelen++;

				// reset current char
				curlen = 0;
				current[0] = '\0';
			}	

		}
		while(!eol);


		// initialize small and large
		int small;
		int large;

		small = line[0];
		large = line[0];

		// iterate through line
	
		for (int i = 0; i < linelen; i++) {
			if (line[i] > large) {
				large = line[i];
			}
			if (line[i] < small) {
				small = line[i];
			}
		}

		int diff = large - small;

		// add difference to checksum
		checksum += diff;

		printf("largest: %d; smallest: %d; difference: %d\n", large, small, diff);

		if (*input == '\0') {
			eoi = true;
		}

	} while (!eoi);

	printf("checksum: %d\n", checksum);
	return 0;
}
