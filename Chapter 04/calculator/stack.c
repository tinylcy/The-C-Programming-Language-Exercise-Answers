#include <stdio.h>
#include <stdlib.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* Add commands to print the top element of the stack without popping, to duplicate it,
 * and to swap the top two elements. Add a command to clear the stack. */

double top(void) {
	if (sp <= 0) {
		printf("error: stack empty\n");
		return EXIT_FAILURE;
	}
	return val[sp - 1];
}

void dup(void) {
	if (sp < MAXVAL) {
		push(top());
	} else {
		printf("error: stack full, can't dup\n");
	}
}

void swap(void) {
	double op1 = pop();
	double op2 = pop();
	push(op1);
	push(op2);
}

void empty(void) {
	sp = 0;
}