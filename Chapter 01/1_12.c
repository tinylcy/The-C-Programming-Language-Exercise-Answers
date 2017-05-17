#include <stdio.h>

/*
 * Write a program that prints its input one word per line.
 */
int main(void) {
	int c;
	int inspace = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (inspace == 0) {
				putchar('\n');
				inspace = 1;
			}
		} else {
			putchar(c);
			inspace = 0;
		}
	}

	return 0;
}