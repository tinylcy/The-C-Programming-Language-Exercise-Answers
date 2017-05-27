#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UPPER "./upper"
#define LOWER "./lower"

/*
 * Write a program that converts upper case to lower or lower case to upper, 
 * depending on the name it is invoked with, as found in argv[0].
 */
int main(int argc, char const *argv[]) {

	int (*convcase[2])(int) = {tolower, toupper};
	int (*convert)(int);
	int c;

	if (strcmp(argv[0], LOWER) == 0) {
		convert = convcase[0];
	} else if (strcmp(argv[0], UPPER) == 0) {
		convert = convcase[1];
	} else {
		fprintf(stderr, "unkonwn operation.\n");
		return -1;
	}

	while ((c = getchar()) != EOF) {
		putchar(convert(c));
	}

	return 0;
}