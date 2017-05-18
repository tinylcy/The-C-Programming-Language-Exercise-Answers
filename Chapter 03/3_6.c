#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

void itoa(int n, char s[], int width);
void reverse(char line[]);
int abs(int n);

/*
 * Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width;
 * the converted number must be padded with blanks on the left if necessary to make it wide enough.
 */
int main(void) {
	char s[MAXLEN];
	itoa(255, s, 6);
	printf("s: %s\n", s);
	return 0;
}

void itoa(int n, char s[], int width) {
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
	while (i < width) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;
	for ( i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int abs(int n) {
	return n > 0 ? n : -n;
}