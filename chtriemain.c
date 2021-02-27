#include <stdio.h>
#include "chtrie.h"

int main() {
	struct chTrie *root = new_chTrie();
	add_words_fs("the ther there that awesome amazing part parts", root);
	print(root);
	printf("%d\n", w_search(root, "the", 3));
	printf("%0.2f\n", probability(root, "the", 3, "ther", 4));
	return 0;
}

