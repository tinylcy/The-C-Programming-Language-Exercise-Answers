#include <stdio.h>
#define MAXLEN 1000

int _getline(char line[], int lim);
int trim(char line[], int len);

/*
 * Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.
 */
int main(void) {
	char line[MAXLEN];
	int len;

	while ((len = _getline(line, MAXLEN)) != 0) {
		if (trim(line, len) > 0) {
			printf("%s", line);
		}
	}

	return 0;
}

int _getline(char line[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

int trim(char line[], int len) {
	int i, last;
	for (last = 0; line[last] != '\0'; last++) {
		;
	}
	for (i = last - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); i--) {
		line[i] = '\0';
		--len;
	}
	return len;
}