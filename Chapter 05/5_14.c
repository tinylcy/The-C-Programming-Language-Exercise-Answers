#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINE 1000

int getlinex(char s[], int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsortx(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));

int numcmp(char *, char *);
int numcmpr(char *, char *);

char *lineptr[MAXLINE];

int main(int argc, char const *argv[]) {
	int nlines;
	int numeric = 0, numericr = 0;
	int (*comp)(void *, void *);

	if (argc > 1 && argv[1][0] == '-') {
		if (strstr(argv[1], "n")) {
			numeric = 1;
		}
		if (strstr(argv[1], "r")) {
			numericr = 1;
		}
	}

	comp = strcmp;
	if (numeric && !numericr) {
		comp = numeric;
	}
	if (numeric && numericr) {
		comp = numericr;
	}

	if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
		qsortx((void **)lineptr, 0, nlines - 1, comp);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsortx(void *v[], int left, int right,
            int (*comp)(void *, void *)) {

	int i, last;
	void swap(void *v[], int, int);

	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsortx(v, left, last - 1, comp);
	qsortx(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) {
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int numcmp(char *s1, char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2) {
		return -1;
	} else if (v1 > v2) {
		return 1;
	} else {
		return 0;
	}
}

int numcmpr(char *s1, char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2) {
		return 1;
	} else if (v1 > v2) {
		return -1;
	} else {
		return 0;
	}
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

void writelines(char *lineptr[], int nlines) {
	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}
