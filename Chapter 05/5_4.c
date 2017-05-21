#include <stdio.h>

int strend(char *s, char *t);

/*
 * Write the function strend(s,t) , which returns 1 if the string t occurs at the end of the string s , and zero otherwise.
 */
int main(void) {
	char *s = "chenyang";
	char *t = "ang";
	printf("%d\n", strend(s, t));
	return 0;
}

int strend(char *s, char *t) {
	int len = 0;
	while (*s) {
		s++;
	}
	while (*t) {
		len++;
		t++;
	}
	while (len-- && *s-- == *t--) {
		;
	}
	if (len < 0) {
		return 1;
	}
	return 0;
}