#include <stdio.h>

int invert(int x, int p, int n);

/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at position p
 * inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */
int main(void) {
	printf("invert(85, 2, 3): %d\n", invert(85, 2, 3));
	return 0;
}

int invert(int x, int p, int n) {
	int mask = (0x1 << n) - 1;
	return (mask << p) ^ x;
}