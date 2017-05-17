#include <stdio.h>
#include <string.h>

char lower(char c);

/*
 * Rewrite the function lower, which converts upper case letters to lower case, with a
 * conditional expression instead of if-else .
 */
int main(void) {
    char s[] = "AaBbcCD3EdFGHgIJKLhM2NOjPQRkSTlUVWfXYf0Z1";
	int i;
	for (i = 0; i < strlen(s); i++) {
		putchar(lower(s[i]));
	}
	return 0;
}

char lower(char c) {
	return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}