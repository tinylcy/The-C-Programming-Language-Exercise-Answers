#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define TRUE 1
#define FALSE 0

int equals(char *s, char *v);

/*
 * Write a program to compare two files, printing the first line where they differ.
 */
int main(int argc, char const *argv[]) {

	char s[MAXLEN], v[MAXLEN];
	FILE *sfp, *vfp;

	if (argc != 3) {
		fprintf(stderr, "usage: %s file1 file2.\n", argv[0]);
		exit(1);
	}

	if ((sfp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can't not open %s.\n", argv[1]);
		exit(2);
	}
	if ((vfp = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "can't not open %s.\n", argv[2]);
		exit(2);
	}

	while (fgets(s, MAXLEN, sfp) != NULL && fgets(v, MAXLEN, vfp) != NULL) {
		if (!equals(s, v)) {
			fputs("diff:\n", stderr);
			fprintf(stderr, "%s: ", argv[1]);
			fputs(s, stderr);
			fprintf(stderr, "%s: ", argv[2]);
			fputs(v, stderr);
			return 0;
		}
	}

	fprintf(stdout, "no diff.\n");
	return 0;
}

int equals(char *s, char *v) {
	int slen = strlen(s);
	int vlen = strlen(v);
	if (slen != vlen) {
		return FALSE;
	}

	while (*s != '\0' && *s == *v) {
		s++;
		v++;
	}
	if (*s == '\0') {
		return TRUE;
	}

	return FALSE;
}
