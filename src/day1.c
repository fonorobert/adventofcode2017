// handle sequence of digits as null terminated char array
// cast digits in pairs to int, compare, then add
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int sumpairs(char *digits, int step);
int chartoi(char c);
int getnextpos(int pos, int len, int step);

int main(int argc, char *argv[]) {
	char *seq = argv[1];
	int step = 1;

	if(argc == 3 && strcmp(argv[2], "halfway") == 0) {
		step = strlen(seq)/2;
	}

	int sum = sumpairs(seq, step);
	printf("%d\n", sum);
	return 0;
}


int sumpairs(char *digits, int step) {
	int sum = 0;
	int d1 = 0;
	int d2 = 0;
	int len = strlen(digits);

	for(int i = 0; i < len; i++) {
		d1 = chartoi(digits[i]);
		d2 = chartoi(digits[getnextpos(i, len, step)]);
		if (d1 == d2) {
			sum += d1;
		}
		
	}
	
	return sum;
}

int getnextpos(int pos, int len, int step) {
	int nextpos = pos + step;
	if (nextpos >= len) {
		nextpos = nextpos - len;
	}
	return nextpos;
}

int chartoi(char c) {
	int i = c - '0';
	return i;
}
