#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100

struct linelist {
	int line;
	struct linelist *next;
};

struct wordtree {
	char *val;
	struct linelist *list;
	struct wordtree *left;
	struct wordtree *right;
};

int getlinex(char s[], int lim);
int tokenise(char *line, char **words);

struct wordtree*
insert(struct wordtree *root, char *word, int line);
void printtree(struct wordtree *root);
int skip(char *word);

/*
 * Write a cross-referencer that prints a list of all words in a document, and,
 * for each word, a list of the line numbers on which it occurs.
 * Remove noise words like "the," "and," and so on.
 */
int main(void) {
	char *words[MAXLEN];
	char line[MAXLEN];
	int len, num;
	int i, cnt;
	struct wordtree *root = NULL;

	cnt = 1;
	while ((len = getlinex(line, MAXLEN)) > 0) {
		num = tokenise(line, words);
		for (i = 0; i < num; i++) {
			// printf("word: %s\n", words[i]);
			if (skip(words[i])) {
				continue;
			}
			root = insert(root, words[i], cnt);
		}
		cnt++;
	}

	printtree(root);

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

struct wordtree*
insert(struct wordtree *root, char *word, int line) {
	if (root == NULL) {
		root = (struct wordtree*)malloc(sizeof(struct wordtree));
		root->val = (char *)malloc(sizeof(char) * strlen(word));
		strcpy(root->val, word);
		root->left = root->right = NULL;
		struct linelist *list = (struct linelist*)malloc(sizeof(struct linelist));
		list->line = line;
		list->next = NULL;
		root->list = list;
		return root;
	}
	if (strcmp(word, root->val) == 0) {
		struct linelist *list = (struct linelist*)malloc(sizeof(struct linelist));
		list->line = line;
		list->next = root->list;
		root->list = list;
	} else if (strcmp(word, root->val) < 0) {
		root->left = insert(root->left, word, line);
	} else {
		root->right = insert(root->right, word, line);
	}
	return root;
}

void printtree(struct wordtree *root) {
	if (root != NULL) {
		printf("word: %s -> ", root->val);
		struct linelist *list = root->list;
		while (list != NULL) {
			printf("%d ", list->line);
			list = list->next;
		}
		printf("\n");

		printtree(root->left);
		printtree(root->right);
	}
}

static char *skiplist[] = {
	"a",
	"an",
	"and",
	"be",
	"but",
	"by",
	"he",
	"I",
	"off",
	"on",
	"she",
	"so",
	"the",
	"they",
	"you"
};

int skip(char *word) {
	int i;
	for (i = 0; skiplist[i] != '\0'; i++) {
		if (strcmp(skiplist[i], word) == 0) {
			return 1;
		}
	}
	return 0;
}

