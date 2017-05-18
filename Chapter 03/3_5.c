#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

/*
 * Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 */
int main(void) {
	char buffer[10];
	int i;

	for ( i = 2; i <= 20; ++i ) {
		itob(255, buffer, i);
		printf("Decimal 255 in base %-2d : %s\n", i, buffer);
	}
	return 0;
}

void itob(int n, char s[], int b) {
	static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, sign = 1;

	i = 0;
	if (n < 0) {
		sign = -1;
		n = -n;
	}

	do {
		s[i++] = digits[n % b];
		n /= bg;
	} while (n > 0);

	if (sign < 0) {
		s[i] = '-';
	}
	s[i] = '\0';
}

void reverse(char s[]) {
	int c, i, j;
	for ( i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
