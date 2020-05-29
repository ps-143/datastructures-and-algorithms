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
	new->isEnd = 0;
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
			t = t->characters[s[i]-'a'];
		}
		else {
			t->freq++;
			t->isEnd = 1;
			t = root;
		}
	}
	t->isEnd = 1;
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

int w_search(struct chTrie* t, char str[], int length) {
	for(int i = 0; i < length; i++) {
		if(t->characters[str[i] - 'a'] == NULL) {
			return 0;
		}
		t = t->characters[str[i] - 'a'];
	}
	return t->freq;
}

float probability(struct chTrie* t, char stub[], int lenOfStub, char word[], int length) {
	float prob;
	float freqOfStub = w_search(t, stub, lenOfStub);
	float freqOfWord = w_search(t, word, length);
	if(freqOfStub) {
		prob = freqOfWord/freqOfStub;
	}
	return prob;
}

int main() {
	struct chTrie *root = new_chTrie();
	add_words_fs("the ther there that awesome amazing part parts", root);
	print(root);
	printf("%d\n", w_search(root, "the", 3));
	printf("%0.2f\n", probability(root, "the", 3, "ther", 4));
	return 0;
}

