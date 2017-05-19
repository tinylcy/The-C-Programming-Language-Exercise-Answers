#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

/*
 * Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may
 * be followed by e or E and an optionally signed exponent.
 */
int main(void) {
	printf("%f\n", atof("123.45e-6"));
	return 0;
}

double atof(char s[]) {
	double val, power, elem;
	int i, sign, exp, expsign;

	for (i = 0; isspace(s[i]); i++) {
		;
	}

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
	}
	expsign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (exp = 0; isdigit(s[i]); i++) {
		exp = 10 * exp + (s[i] - '0');
	}

	val = sign * val / power;
	elem = (expsign == -1) ? 0.1 : 10.0;
	for (i = 0; i < exp; i++) {
		val *= elem;
	}

	return val;

}