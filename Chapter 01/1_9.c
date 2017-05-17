#include <stdio.h>
#define SPACE ' '

/*
 * Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */
int main(void) {
	int c;
	int inspace = 0;

	while ((c = getchar()) != EOF) {
		if (c == SPACE) {
			if (inspace == 0) {
				putchar(SPACE);
				inspace = 1;
			}
		} else {
			putchar(c);
			inspace = 0;
		}
	}
}