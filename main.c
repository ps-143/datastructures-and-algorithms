#include <stdio.h>
#include "BinarySearch.h"
#include "InsertionSort.h"
#include "MergeSort.h"

void printArr(int A[], int n) {
	for(int i = 0; i<n; i++) printf("%d ", A[i]);
	printf("\n");
}


int main() {
	int A[]={0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//InsertionSort(A, 10);
	MergeSort(A, 0, 9);
	printArr(A, 10);	
	int ind=BinarySearch(A, 0, 9, 5);
	printf("%d\n", ind);
	return 0;
}

