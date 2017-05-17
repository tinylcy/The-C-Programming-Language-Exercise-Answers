#include <stdio.h>
#define MAXLEN  1000

int _getline(char line[], int lim);

/*
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. C comments do not nest.
 */
int main(void) {
	int len;
	char line[MAXLEN];
	int i, in_comment, in_quote;

	while ((len = _getline(line, MAXLEN)) > 0) {
		i = 0;
		in_comment = 0;
		in_quote = 0;

		while (i < len) {
			if (line[i] == '"') {
				if (in_quote == 1) {
					in_quote = 0;
				} else {
					in_quote = 1;
				}
			}
			if (in_quote == 0) { // the statment is not in quote
				if (in_comment) {
					if (line[i] == '*' && line[i + 1] == '/') {
						in_comment = 0;
						++i;
					}
				} else {
					if (i + 1 < len && line[i] == '/' && line[i + 1] == '/') { // comment format: // ...
						printf("\n");
						break;
					}
					if (line[i] == '/' && line[i + 1] == '*') {  // comment format: /* ... */
						in_comment = 1;
						++i;
					} else {
						putchar(line[i]);
					}
				}
			} else {
				putchar(line[i]);
			}
			++i;
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