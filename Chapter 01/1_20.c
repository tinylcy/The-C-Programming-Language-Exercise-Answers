#include <stdio.h>
#define MAXLEN 1024
#define TAB '\t'
#define SPACE ' '
#define N 5

int _getline(char line[], int lim);
int cal_space_num(int i);

/*
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. 
 * Assume a fixed set of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 */
int main(void) {
	char line[MAXLEN];
	int len;

	while ((len = _getline(line, MAXLEN)) > 0) {
		int i, j;
		for (i = 0; i < len; i++) {
			if (line[i] == TAB) {
				int spaces = cal_space_num(i);
				for (j = 0; j < spaces; j++) {
					putchar(SPACE);
				}
			} else {
				putchar(line[i]);
			}
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

int cal_space_num(int i) {
	return N - i % N;
}
