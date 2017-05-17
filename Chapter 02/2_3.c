#include <stdio.h>
#include <string.h>

int htoi(char s[]);

/*
 * Write the function htoi(s) , which converts a string of hexadecimal digits (including an optional 0x or 0X) into 
 * its equivalent integer value. 
 * The allowable digits are 0 through 9, a through f, and A through F .
 */
int main(void) {
	printf("0x12 = %d\n", htoi("0x12"));
	printf("0x1f = %d\n", htoi("0x1f"));
	printf("0x1F = %d\n", htoi("0x1F"));
	return 0;
}

int htoi(char s[]) {
	int i = 0;
	int result, len, val;

	if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
		i = 2;
	}

	len = strlen(s);
	result = 0;
	val = 0;
	for (; i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			val = s[i] - '0';
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			val = s[i] - 'a' + 10;
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			val = s[i] - 'A' + 10;
		}
		result = result * 16 + val;
	}

	return result;
}