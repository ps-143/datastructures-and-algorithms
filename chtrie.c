#include <stdio.h>
#include <stdlib.h>

#define ALPHABETSIZE 26

struct chTrie {
	struct chTrie *characters[ALPHABETSIZE];
	int freq;
	int isEnd;
};

struct chTrie* new_chTrie() {
	struct chTrie* new  = (struct chTrie*)malloc(sizeof(struct chTrie));
	for(int i = 0; i<26; i++) {
		new->characters[i] = NULL;
	}
	new->freq = 0;
	new->isEnd = 1;
	return new;
}

void add_words_fs(char s[], struct chTrie* root) {
	struct chTrie* t = root;
	for(int i = 0; s[i] != '\0'; i++) {
		if(s[i] != ' ') {
			if(t->characters[s[i]-'a'] == NULL) {
				t->characters[s[i]-'a'] = new_chTrie();
			}
			t->freq++;
			t->isEnd = 0;
			t = t->characters[s[i]-'a'];
		}
		else {
			t->freq++;
			t = root;
		}
	}
	t->freq++;
}

void print_words(struct chTrie* root, char str[], int level) {
	if(root->isEnd == 1) {
		str[level] = '\0';
		printf("%d %s\n", root->freq, str);
	}
	struct chTrie* t = root;
	for(int i = 0; i<26; i++) {
		if(root->characters[i]) {
			str[level] = i + 'a';
			print_words(root->characters[i], str, level+1);
		}
	}
}

void print(struct chTrie* root) {
	int level = 0;
	char str[50];
	print_words(root, str, level);
}

int main() {
	struct chTrie *root = new_chTrie();
	add_words_fs("the that awesome amazing", root);
	print(root);
	return 0;
}

