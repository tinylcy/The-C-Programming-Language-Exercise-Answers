#include <stdio.h>
#define MAXLEN 1000

int _getline(char line[], int lim);
void copy(char from[], char to[]);

/*
 * Revise the main routine of the longest-line program so it will correctly print the length of
 * arbitrarily long input lines, and as much as possible of the text.
 */
int main(void) {
	char line[MAXLEN], longest[MAXLEN];
	int len, maxlen = 0;

	while ((len = _getline(line, MAXLEN)) != 0) {
		printf("len = %d, line = %s", len, line);
		if (len > maxlen) {
			maxlen = len;
			copy(line, longest);
		}
	}

	printf("\nlongest: %s\n", longest);

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

void copy(char from[], char to[]) {
	int i;
	for (i = 0; from[i] != '\0'; i++) {
		to[i] = from[i];
	}
	from[i] = '\0';
}