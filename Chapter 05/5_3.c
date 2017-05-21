#include <stdio.h>
#define MAXLEN 100

void strcatx(char *s, char *t);

/*
 * Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies 
 * the string t to the end of s .
 */
int main(void) {
	char s[MAXLEN] = "chenyang ";
	char t[MAXLEN] = "li";
	strcatx(s, t);
	printf("s = %s\n", s);
	return 0;
}

void strcatx(char *s, char *t) {
	while (*s) {
		s++;
	}
	while (*t) {
		*s++ = *t++;
	}
	*s = '\0';
}
