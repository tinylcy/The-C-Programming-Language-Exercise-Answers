#include <stdio.h>
#define MAXLEN 1000
#define MINLENGTH 80

int _getline(char line[], int lim);

/*
 * Write a program to print all input lines that are longer than 80 characters.
 */
int main(void) {
	char line[MAXLEN];
	int len;

	while ((len = _getline(line, MAXLEN)) != 0) {
		if (len > MINLENGTH) {
			printf("len = %d, line = %s", len, line);
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
