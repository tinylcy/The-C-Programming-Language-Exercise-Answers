#include <stdarg.h>
#include <stdio.h>

/*
 * Modify the minprintf function to add more features of printf function.
 */
void minprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); // make ap point to 1st unnamed arg.
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'x':
			ival = va_arg(ap, int);
			printf("%x", ival);
			break;
		case 'u':
			ival = va_arg(ap, int);
			printf("%u", ival);
			break;
		case 'c':
			ival = va_arg(ap, int);
			putchar(ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
			}
			break;
		case '%':
			putchar('%');
			break;
		default:
			putchar(*p);
			break;
		}
	}

	va_end(ap);
}

int main(void) {
	minprintf("int = %d\n", 1024);
	minprintf("double = %f\n", 2048.0);
	minprintf("string = %s\n", "chenyang li");
	minprintf("char = %c\n", 65);
	minprintf("unsigned int = %u\n", 24);
	minprintf("%%\n");
	return 0;
}