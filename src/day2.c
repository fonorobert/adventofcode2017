// checksum: sum of differences between largest and smallest value on each line
// spreadsheet: entered as command line argument, delimiter is LF (coded 10 in ascii)
// use strtok() to tokenize string input

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib/utils.h"

char *ptr;
long inlen;
long linediff();

int main(int argc, char *argv[]) {
	
	int checksum = 0;

	char *input = argv[1];
	inlen = strlen(input);
	ptr = input;
	
	long curdiff = 0;
	printf("&ptr: %ld, *ptr: %c\n", ptr, *ptr);
	do {
		curdiff = linediff();
		//TODO: stop ptr from moving past EOI
		//need to detect EOI somehow
		if(&ptr<&input+inlen-1){
			ptr++;
		}
		printf("%d\n", curdiff);
		checksum += curdiff;
		printf("&ptr: %ld, *ptr: %c\n", ptr, *ptr);
	} while(curdiff != -1);
	printf("EOI, diff: %ld\n", curdiff);
	return 0;
}

long linediff() {
	if(!isdigit(*ptr)) {
		return -1;
	}

	long large = 0;
	long small = 999999999999999999;
	long diff = 0;
	
	do {
		int i = 0;
		char buffer[40] = {'\0'};

		do {
			buffer[i] = *ptr;
			i++;
			ptr++;
			buffer[i] = '\0';
		} while (isdigit(*ptr));
		
		long num = atol(buffer);

		if(num > large) {
			large = num;
		} else if (num < small) {
			small = num;
		}
	} while (*ptr != 10);

	
	diff = large - small;	
	return diff;
}
