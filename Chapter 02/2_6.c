#include <stdio.h>

int setbits(int x, int p, int n, int y);

/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
 * position p set to the rightmost n bits of y, leaving the other bits unchanged. 
 */
int main(void) {

	printf("setbits(11, 1, 2, 6): %d\n", setbits(11, 1, 2, 6));
	printf("setbits(11, 2, 2, 6): %d\n", setbits(11, 2, 2, 6));
	printf("setbits(54, 2, 3, 9): %d\n", setbits(54, 2, 3, 9));

	return 0;
}

int setbits(int x, int p, int n, int y) {
	int mask = (0x1 << n) - 1;
	return ((~(mask << p)) & x) | ((mask & y) << p);
}