#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void _reverse(char s[], int i, char x);

static int cur;

/* 
 * Write a recursive version of the function reverse(s) , which reverses the string s in place. 
 */
int main(void) {
	char s[] = "chenyang li";
	reverse(s);
	printf("%s\n", s);
	return 0;
}

void reverse(char s[]) {
	cur = 0;
	_reverse(s, 0, s[0]);
}

void _reverse(char s[], int i, char x) {
	if (s[i] == '\0') {
		return;
	}
	_reverse(s, i + 1, s[i + 1]);
	s[cur++] = x;
}
