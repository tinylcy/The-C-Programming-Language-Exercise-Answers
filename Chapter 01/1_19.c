#include <stdio.h>
#define MAXLEN 1000

int _getline(char line[], int lim);
void reverse(char line[], int len);

/*
 * Write a function reverse(s) that reverses the character string s .
 * Use it to write a program that reverses its input a line at a time.
 */
int main(void) {
	char line[MAXLEN];
	int len;

	while ((len = _getline(line, MAXLEN)) > 0) {
		reverse(line, len);
		printf("%s", line);
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

void reverse(char line[], int len) {
	int i, j;
	char tmp;
	// skip the last series of \n
	for (j = len - 1; j >= 0 && line[j] == '\n'; --j) {
		;
	}
	for (i = 0; i < j; ++i, --j) {
		tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}
}