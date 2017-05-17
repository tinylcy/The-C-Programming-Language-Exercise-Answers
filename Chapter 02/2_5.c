#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);
int location(char s[], int c);

/*
 * Write the function any(s1,s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs,
 * or -1 if s1 contains no characters from s2. (The standard library
 * function strpbrk does the same job but returns a pointer to the
 * location.) 
 */
int main(void) {
	char s1[] = "chenyang";
	char s2[] = "tinylcy";
	printf("loc: %d\n", any(s1, s2));
	return 0;
}

/*
 * any() return the first character in s1 that occurs in s2, which considers every
 * character in s2(but not any as exercise indicates).
 */
int any(char s1[], char s2[]) {
	int i;
	int loc, min;

	for (i = 0, min = strlen(s1); s2[i] != '\0'; i++) {
		if ((loc = location(s1, s2[i])) != -1) {
			if (loc < min) {
				min = loc;
			}
		}
	}

	if (min == strlen(s1)) {
		return -1;
	}
	return min;
}

int location(char s[], int c) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == c) {
			return i;
		}
	}
	return -1;
}