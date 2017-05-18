#include <stdio.h>
#define MAXLEN 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/*
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences
 * like \n and \t as it copies the string t to s . Use a switch .
 * Write a function for the other direction as well, converting escape sequences into the real characters.
 */
int main(void) {
	char s[] = "abcd\nef\tghi";
	char t[MAXLEN];
	char v[MAXLEN];
	escape(s, t);
	printf("t: %s\n", t);
	unescape(t, v);
	printf("v: %s\n", v);
	return 0;
}

void escape(char s[], char t[]) {
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\\':

			switch (s[i + 1]) {
			case 'n':
				t[j++] = '\n';
				i++;
				break;
			case 't' :
				t[j++] = '\t';
				i++;
				break;
			default:
				t[j++] = '\\';
				break;
			}

			break;

		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}