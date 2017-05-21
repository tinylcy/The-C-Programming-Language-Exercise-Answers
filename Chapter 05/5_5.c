#include <stdio.h>
#include <string.h>
#define MAXLEN 100

char *strncpyx(char *s, char *t, int n);
char *strncatx(char *s, char *t, int n);
int strncmpx(char *s, char *t, int n);

/*
 * Write versions of the library functions strncpy , strncat , and strncmp ,
 * which operate on at most the first n characters of their argument strings. For example,
 * strncpy(s,t,n) copies at most n characters of t to s .
 * Full descriptions are in Appendix B.
 */
int main(void) {

	char s1[MAXLEN] = "bbcde";
	char t1[MAXLEN] = "abcedf";
	printf("%s\n", strncpyx(s1, t1, 6));

	char s2[MAXLEN] = "bbcde";
	char t2[MAXLEN] = "abcedf";
	printf("%s\n", strncatx(s2, t2, 6));

	char *s3 = "bbcde";
	char *t3 = "abcedf";
	printf("%d\n", strncmpx(s3, t3, 6));

	return 0;
}

char *strncpyx(char *s, char *t, int n) {
	char *ret = s;
	int tlen = strlen(t);
	n = (n < tlen) ? n : tlen;
	while (n--) {
		*s++ = *t++;
	}
	*s = '\0';
	return ret;
}

char *strncatx(char *s, char *t, int n) {
	char *ret = s;
	int tlen = strlen(t);
	n = (n < tlen) ? n : tlen;
	while (*s) {
		s++;
	}
	while (n--) {
		*s++ = *t++;
	}
	*s = '\0';
	return ret;
}

int strncmpx(char *s, char *t, int n) {
	int slen = strlen(s);
	int tlen = strlen(t);
	int min = slen < tlen ? slen : tlen;
	n = min < n ? min : n;
	while (n--) {
		if (*s != *t) {
			return *s - *t;
		}
		s++;
		t++;
	}
	return 0;
}
