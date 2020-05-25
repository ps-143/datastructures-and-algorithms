#include "InsertionSort.h"

void InsertionSort(int A[], int n) {
	int j = 1;
	while(j < n) {
		int i = j - 1;
		int key = A[j];
		while(key < A[i] && i >= 0) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
		j++;
	}
}

	
