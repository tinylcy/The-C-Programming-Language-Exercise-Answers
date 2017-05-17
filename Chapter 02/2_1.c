#include <stdio.h>
#include <limits.h>

/*
 * Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned,
 * by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */
int main(void) {

	printf("Size of Char %d\n", CHAR_BIT);
	printf("Size of Char Max %d\n", CHAR_MAX);
	printf("Size of Char Min %d\n", CHAR_MIN);

	printf("Size of int min %d\n", INT_MIN);
	printf("Size of int max %d\n", INT_MAX);

	printf("Size of long min %ld\n", LONG_MIN);
	printf("Size of long max %ld\n", LONG_MAX);

	printf("Size of short min %d\n", SHRT_MIN);
	printf("Size of short max %d\n", SHRT_MAX);

	printf("Size of unsigned char %d\n", UCHAR_MAX);
	printf("Size of unsigned long %lu\n", ULONG_MAX);
	printf("Size of unsigned int %u\n", UINT_MAX);
	printf("Size of unsigned short %d\n", USHRT_MAX);

	return 0;
}
