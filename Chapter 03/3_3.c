#include <stdio.h>
#define MAXLEN 1000

void expand(char s1[], char s2[]);

/*
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2 .
 * Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z .
 * Arrange that a leading or trailing - is taken literally.
 */
int main(void) {
	char s1[] = "-a-f-z0-9A-G-Z-";
	char s2[MAXLEN];
	expand(s1, s2);
	printf("s2 = %s\n", s2);
	return 0;
}

void expand(char s1[], char s2[]) {
	int i , j;
	char before = '\0', after = '\0';

	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '-' && i - 1 >= 0 && s1[i + 1] != '\0') {
			before = s1[i - 1];
			after  = s1[i + 1];
			for (char c = before + 1; c < after; c++) {
				s2[j++] = c;
			}
		} else {
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}