#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 3

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtable[HASHSIZE];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
void freex(struct nlist *np);

/*
 * Write a function undef that will remove a name and definition from
 * the table maintained by lookup and install .
 */
int main(void) {
	install("Z", "z");
	install("B", "b");
	install("F", "f");
	install("D", "d");
	install("U", "u");

	undef("F");

	int i;
	struct nlist *cur;
	for (i = 0; i < HASHSIZE; i++) {
		cur = hashtable[i];
		while (cur) {
			printf("name: %s, defn: %s\n", cur->name, cur->defn);
			cur = cur->next;
		}
	}

	return 0;
}

unsigned hash(char *s) {
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

struct nlist* lookup(char *s) {
	struct nlist *np;

	for (np = hashtable[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
}

struct nlist *install(char *name, char *defn) {
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *)malloc(sizeof(*np));
		np->name = (char *)malloc(sizeof(char) * strlen(name));
		strcpy(np->name, name);
		hashval = hash(name);
		np->next = hashtable[hashval];
		hashtable[hashval] = np;
	} else {
		free((void*)np->defn);
	}

	np->defn = (char *)malloc(sizeof(char) * strlen(defn));
	strcpy(np->defn, defn);

	return np;
}

void undef(char *name) {
	struct nlist *np, *pre, *cur;
	unsigned hashval;

	if ((np = lookup(name))) {
		hashval = hash(name);
		cur = hashtable[hashval];
		if (cur == np) {
			hashtable[hashval] = cur->next;
			freex(cur);
			return;
		} else {
			pre = cur;
			cur = cur->next;
			while (cur) {
				if (cur == np) {
					pre->next = cur->next;
					freex(cur);
					return;
				}
				pre = cur;
				cur = cur->next;

			}
		}

	}
}

void freex(struct nlist *np) {
	free((void *)np->name);
	free((void *)np->defn);
	free((void *)np);
}
