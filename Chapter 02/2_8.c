#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

/*
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */
int main(void) {
	printf("rightrot(23, 4) = %u\n", rightrot(23, 4));
	return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n) {
	while (n--) {
		if ((x & 0x1) == 1) {
			x = (x >> 1) | ~(~0x0U >> 1);
		} else {
			x = (x >> 1);
		}
	}

	return x;
}