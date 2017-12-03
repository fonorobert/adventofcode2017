// checksum: sum of differences between largest and smallest value on each line
// spreadsheet: entered as command line argument, delimiter is LF (coded 10 in ascii)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lib/utils.h"

int checksum(char *input);

int main(int argc, char *argv[]) {
	int result = checksum(argv[1]);
	printf("checksum: %d\n", result);
	return 0;
}

int checksum(char *input) {
	int large = 0;
	int small = 0;
	int current = 0;
	int checksum = 0;
	int len = strlen(input);

	// set first digit as both small and large
	small = chartoi(input[0]);
	large = chartoi(input[0]);

//	printf("len %d small %d large %d\n\n", len, small, large);

	for (int i = 0; i<=len; i++) {
	//	printf("i %d\n", i);
		// calculate difference, then reset if end of line
		if (input[i] == 10 || i == len) {
	//		printf("small %d large %d diff %d\n", small, large, large-small);
			if (large > small) {
				checksum += large - small;
			//	printf("cur sum %d\n", checksum);
			}
			if(i == len) {
			//	printf("end of input");
				return checksum;
			}
			if (i<len) {
				large = chartoi(input[i+1]);
				small = chartoi(input[i+1]);
			} else {
				break;
			}
			continue;
		}
		if (!isdigit(input[i])) {
			continue;
		}

		current = chartoi(input[i]);
		
		if (current > large) { 
			large = current;
		}

		if (current < small) {
			small = current;
		}
	}

}
