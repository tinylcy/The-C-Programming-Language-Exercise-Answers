#include <stdio.h>
#define MAXLEN 1000

/*
 * Write a loop equivalent to the for loop below without using && or || .
 *
 * for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *    s[i] = c;
 */
int main(void) {
	int c;
	int i, lim = MAXLEN;
	char s[MAXLEN];

	i = 0;

	/* old version */
	// while (true) {
	// 	if (i < lim - 1) {
	// 		if ((c = getchar()) != '\n') {
	// 			if (c != EOF) {
	// 				s[++i] = c;
	// 			} else {
	// 				break;
	// 			}
	// 		} else {
	// 			break;
	// 		}
	// 	} else {
	// 		break;
	// 	}
	// }

	/* new version */
	while (i < lim - 1) {
		c = getchar();
		if (c == '\n') {
			break;
		} else if (c == EOF) {
			break;
		}
		s[++i] = c;
	}

	return 0;
}