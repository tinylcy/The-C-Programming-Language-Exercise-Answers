#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100
#define MAXWORDS 1000

struct word {
	char *val;
	int cnt;
	struct word *next;
};

int getlinex(char s[], int lim);
int tokenise(char *line, char **words);

void insert(char *word);
void transfer(struct word *head, struct word **list);
int partition(int low, int high);
void sort();
void print();
void swap(struct word**list, int i, int j);

static struct word *head = NULL;
static int wordcount;
static struct word *list[MAXWORDS];

/*
 * Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurrence.
 * Precede each word by its count.
 */
int main(void) {
	char *words[MAXLEN];
	char line[MAXLEN];
	int len, num;
	int i;

	while ((len = getlinex(line, MAXLEN)) > 0) {
		num = tokenise(line, words);
		for (i = 0; i < num; i++) {
			insert(words[i]);
		}
	}
	transfer(head, list);
	sort(0, wordcount - 1);
	print();

	return 0;
}

int getlinex(char s[], int lim) {
	int c;
	int i = 0;
	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}

int tokenise(char *line, char **words) {
	char *start = NULL;
	char *end = NULL;
	int i = 0;

	start = line;

	while (*start != '\0') {
		while (*start != '\0' && isspace(*start)) {
			start++;
		}
		end = start;
		while (*end != '\0' && !isspace(*end)) {
			end++;
		}
		// printf("start = %c, end = %c\n", *start, *end);
		if (*start != '\0') {
			words[i] = malloc(sizeof(char) * (end - start + 1));
			strncpy(words[i++], start, end - start);
		}
		start = end;
	}

	return i;
}

void insert(char *word) {
	struct word *cur, *new;
	if (head == NULL) {
		head = (struct word *)malloc(sizeof(struct word));
		head->val = (char *)malloc(sizeof(strlen(word)));
		strncpy(head->val, word, strlen(word));
		head->cnt = 1;
		head->next = NULL;
	} else {
		cur = head;
		while (cur != NULL) {
			if (strcmp(cur->val, word) == 0) {
				cur->cnt++;
				break;
			} else {
				cur = cur->next;
			}
		}
		if (cur == NULL) {
			new = (struct word *)malloc(sizeof(struct word));
			new->val = (char *)malloc(sizeof(strlen(word)));
			strncpy(new->val, word, strlen(word));
			new->cnt = 1;
			new->next = head;
			head = new;
		}
	}
}

void print() {
	int i;
	for (i = 0; i < wordcount; i++) {
		printf("%s: %d\n", list[i]->val, list[i]->cnt);
	}
}

void transfer(struct word *head, struct word **list) {
	struct word *cur = head;
	int i = 0;
	wordcount = 0;
	while (cur) {
		list[i++] = cur;
		cur = cur->next;
		wordcount++;
	}
}
void sort(int low, int high) {
	if (low >= high) {
		return;
	}
	int mid = partition(low, high);
	sort(low, mid - 1);
	sort(mid + 1, high);
}

int partition(int low, int high) {
	int i, j, pivot;
	i = low;
	j = high + 1;
	pivot = low;
	while (1) {
		while (list[++i]->cnt >= list[pivot]->cnt) {
			if (i == high) {
				break;
			}
		}
		while (list[--j]->cnt <= list[pivot]->cnt) {
			if (j == low) {
				break;
			}
		}
		if (i >= j) {
			break;
		}
		swap(list, i, j);
	}
	swap(list, j, pivot);
	return j;
}

void swap(struct word **list, int i, int j) {
	struct word *tmp;
	tmp = list[i];
	list[i] = list[j];
	list[j] = tmp;
}
