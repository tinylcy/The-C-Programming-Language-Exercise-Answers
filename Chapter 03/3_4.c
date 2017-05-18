#include <stdio.h>
#include <limits.h>
#define MAXLEN 1000

void itoa(int n, char s[]);
void reverse(char line[], int len);
int abs(int n);

/*
 * In a two's complement number representation, our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to -(2 to the power (wordsize - 1)) . Explain why not.
 * Modify it to print that value correctly regardless of the machine on which it runs.
 */
int main(void) {
	char s[MAXLEN];
	itoa(INT_MIN, s);
	printf("s: %s\n", s);
	return 0;
}

// void itoa(int n, char s[]) {
// 	long ln = (long)n;
// 	int i, sign = 1;

// 	if (ln < 0) {
// 		sign = -1;
// 		ln = -ln;
// 	}
// 	i = 0;
// 	do {
// 		s[i++] = ln % 10 + '0';
// 	} while ((ln /= 10) > 0);

// 	if (sign < 0) {
// 		s[i++] = '-';
// 	}
// 	s[i] = '\0';
// 	reverse(s, i);
// }

void itoa(int n, char s[]) {
	int i, sign = 1;
	if (n < 0) {
		sign = -1;
	}

	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
		n /= 10;
	} while (n != 0);

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s, i);
}

void reverse(char line[], int len) {
	int i, j;
	char tmp;
	// skip the last series of \n
	for (j = len - 1; j >= 0 && line[j] == '\n'; --j) {
		;
	}
	for (i = 0; i < j; ++i, --j) {
		tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}
}

int abs(int n) {
	return n > 0 ? n : -n;
}