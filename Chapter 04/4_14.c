#include <stdio.h>

#define swap(t,x,y) {	\
	(t)=(*(x));			\
	(*(x))=(*(y));		\
	(*(y))=(t);			\
}

/*
 * Define a macro swap(t,x,y) that interchanges two arguments of type t . (Block structure will help.)
 */
int main(void) {

	int ix = 1024, iy = 2048, it;
	printf("ix = %d, iy = %d\n", ix, iy);
	swap(it, &ix, &iy);
	printf("ix = %d, iy = %d\n", ix, iy);

	double dx = 1024.0, dy = 2048.0, dt;
	printf("dx = %f, dy = %f\n", dx, dy);
	swap(dt, &dx, &dy);
	printf("dx = %f, dy = %f\n", dx, dy);

	char *s1 = "abc", *s2 = "def", *st;
	printf("s1 = %s, s2 = %s\n", s1, s2);
	swap(st, &s1, &s2);
	printf("s1 = %s, s2 = %s\n", s1, s2);

	return 0;
}