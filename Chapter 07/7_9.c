#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

static char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int isupper(char c);

/*
 * Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
 */
int main(void) {
	char chs[] = "aBcDeF";
	int i;

	for (i = 0; chs[i] != '\0'; i++) {
		printf("%c isupper: %s\n", chs[i], isupper(chs[i]) == TRUE ? "true" : "false");
	}

	return 0;
}

int isupper(char c) {
	if (strchr(UPPER, c) != NULL) {
		return TRUE;
	}
	return FALSE;
}