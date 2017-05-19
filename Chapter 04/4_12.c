#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void itoa(int n);
void _itoa(int n);

static char s[MAXLEN];
static int i = 0;

/*
 * Adapt the ideas of printd to write a recursive version of itoa ; 
 * that is, convert an integer into a string by calling a recursive routine.
 */
int main(void) {
	itoa(1024);
	printf("s = %s\n", s);
	itoa(-1024);
	printf("s = %s\n", s);
	itoa(24);
	printf("s = %s\n", s);
	return 0;
}

void itoa(int n) {
	i = 0;
	memset(s, '\0', MAXLEN);
	_itoa(n);
}

void _itoa(int n) {
	if (n == 0) {
		return;
	}
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	_itoa(n / 10);
	s[i++] = n % 10 + '0';
}
