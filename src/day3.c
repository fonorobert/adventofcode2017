#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/utils.h"

#define false 0
#define true 1

int part1(char *input);

int main(int argc, char *argv[]) {

	char *input = argv[1];
	//DEBUG
	

	int result1 = part1(input);

	printf("main input: %s\n", input);
	printf("part1: %d\n", result1);

	return 0;

}


int part1(char *input) {

	char *line = linesplit(input);
	printf("line: %c\n", line[1]);
	return 0;


}
