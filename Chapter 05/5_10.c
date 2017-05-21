#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

static int stack[MAXLEN];
static int sp = 0;

void push(int val);
int pop();

/*
 * Write the program expr , which evaluates a reverse Polish expression from the command line, 
 * where each operator or operand is a separate argument. 
 * For example, expr 2 3 4 + *  evaluates 2 X (3+4).
 */
int main(int argc, char const *argv[]) {
	int i;
	for (i = 1; argv[i] != '\0'; i++) {
		// printf("argv[%d] = %s\n", i, argv[i]);
		if (strcmp(argv[i], "+") == 0) {
			push(pop() + pop());
		} else if (strcmp(argv[i], "-") == 0) {
			int op2 = pop();
			push(pop() - op2);
		} else if (strcmp(argv[i], "*") == 0) {
			push(pop() * pop());
		} else if (strcmp(argv[i], "/") == 0) {
			int op2 = pop();
			if (op2 == 0) {
				printf("division by zero.\n");
				break;
			}
			push(pop() / op2);
		} else {
			push(atoi(argv[i]));
		}
	}

	int result = pop();
	printf("result = %d\n", result);

	return 0;
}

void push(int val) {
	if (sp < MAXLEN) {
		stack[sp++] = val;
	} else {
		printf("stack is full.\n");
	}
}

int pop() {
	if (sp == 0) {
		printf("stack is empty.\n");
		return -1;
	} else {
		return stack[--sp];
	}
}
