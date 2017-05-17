#include <stdio.h>
#define MAXLEN 20

/*
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 */
int main(void) {
	int c;
	int len, wordlen[MAXLEN];
	int inspace = 0;

	for (int i = 0; i < MAXLEN; i++) {
		wordlen[i] = 0;
	}

	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (inspace == 0) {
				++wordlen[len];
				inspace = 1;
				len = 0;
			}
		} else {
			++len;
			inspace = 0;
		}
	}

	// horizontal
	for (int i = 1; i < MAXLEN; i++) {
		printf("%2d ", i);
		for (int j = 0; j < wordlen[i]; j++) {
			printf("#");
		}
		printf("\n");
	}

	printf("\n");

	// vertical
	int maxlen = 0;
	for (int i = 1; i < MAXLEN; i++) {
		if (wordlen[i] > maxlen) {
			maxlen = wordlen[i];
		}
	}
	for (int i = maxlen; i > 0; i--) {
		printf("%2d", i);
		for (int j = 1; j < MAXLEN; j++) {
			if (i <= wordlen[j]) {
				printf(" #");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("  ");
	for (int i = 1; i < MAXLEN; i++) {
		printf("%2d", i);
	}
	printf("\n");

	return 0;
}