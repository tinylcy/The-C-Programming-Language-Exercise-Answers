#include <stdio.h>
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);
int exist(char s[], char c);

/*
 * Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2.
 */
int main(void) {
	char s1[] = "chenyang li";
	char s2[] = "tinylcy";
	squeeze(s1, s2);
	printf("s1 = %s\n", s1);

	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;
	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if (!exist(s2, s1[i])) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

int exist(char s[], char c) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			return TRUE;
		}
	}
	return FALSE;
}