#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINE 1000

int getlinex(char s[], int lim);
int readlines(char *lineptr[], int maxlines);

/*
 * Write the program tail, which prints the last n lines of its input.
 * By default, n is 10, say, but it can be changed by an optional argument, so that
 *
 * tail -n
 *
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n.
 * Write the program so it makes the best use of available storage;
 * lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.
 */
int main(int argc, char const *argv[]) {
	char *lineptr[MAXLINE];
	int i, nlines;
	int c, tailnum;
	nlines = readlines(lineptr, MAXLINE);

	while (--argc > 0 && (*(++argv))[0] == '-') {
		tailnum = atoi(&((*argv)[1]));
	}

	// printf("tailnum = %d\n", tailnum);

	i = (nlines - tailnum < 0) ? 0 : nlines - tailnum;
	while (i < nlines) {
		printf("%s", lineptr[i++]);
	}

	return 0;
}

int getlinex(char s[], int lim) {
	int c;
	int i = 0;
	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getlinex(line, MAXLEN)) > 0) {
		if (nlines > maxlines || (p = (char *)malloc((len + 1) * sizeof(char))) == NULL) {
			return -1;
		} else {
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}
