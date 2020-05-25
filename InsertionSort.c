#include "InsertionSort.h"

void InsertionSort(int A[], int n) {
	int j = 1;
	while(j < n) {
		int key = A[j];
		int i = j - 1;
		while(i) {
			if(key < A[i]) {
				break;
			}
			A[i+1] = A[i--];
		}
		A[i] = key;
		j++;
	}
}

	
