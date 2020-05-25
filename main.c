#include <stdio.h>
#include "BinarySearch.h"

int main() {
	int A[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ind=BinarySearch(A, 0, 8, 5);
	printf("%d\n", ind);
	return 0;
}

