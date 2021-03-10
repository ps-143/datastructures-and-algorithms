#ifndef CHTRIE_H
#define CHTRIE_H

#define ALPHABETSIZE 26

struct chTrie {
	struct chTrie *characters[ALPHABETSIZE];
	int freq;
	int isEnd;
};

struct chTrie* new_chTrie(); 
void add_words_fs(char s[], struct chTrie* root);
void print(struct chTrie* root);
int w_search(struct chTrie* t, char str[], int length);
float probability(struct chTrie* t, char stub[], int lenOfStub, char word[], int length);

#endif

