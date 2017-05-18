#include <stdio.h>
#define EXECCNT 1000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

/*
 * Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure the difference in run-time.
 */
int main(void) {
	int test[] = {1, 3, 5, 7, 9, 11, 13};
	int len = sizeof(test) / sizeof(int);
	for (int cnt = 0; cnt < EXECCNT; cnt++) {
		for (int i = 0; i < len; i++) {
			binsearch2(test[i], test, len);
		}
	}
	return 1;
}

int binsearch(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;
	while ( low <= high ) {
		mid = (low + high) / 2;
		if ( x < v[mid] )
			high = mid - 1;
		else if ( x > v[mid] )
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch2(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && v[mid] != x) {
		if (x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	if (v[mid] == x) {
		return mid;
	}
	return -1;
}
