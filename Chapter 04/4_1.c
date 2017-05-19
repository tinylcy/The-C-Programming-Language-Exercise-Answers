#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

/*
 * Write the function strrindex(s,t) , which returns the position of the rightmost occurrence of t in s, 
 * or -1 if there is none.
 */
int main(void) {
	char s[] = "abcdefghijklmn";
	char t[] = "bcd";
	printf("%d\n", strrindex(s, t));
	return 0;
}

int strrindex(char s[], char t[]) {
	int slen = strlen(s);
	int tlen = strlen(t);
	int i, j, k;

	for (i = slen - 1; i >= tlen - 1; i--) {
		for (j = tlen - 1, k = i; j >= 0 && s[k] == t[j]; j--, k--) {
			;
		}
		if (j == -1) {
			return i - tlen + 1;
		}
	}

	return -1;
}