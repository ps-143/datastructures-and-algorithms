#include "MergeSort.h"

void merge(int A[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	
	for(int i = 0; i < n1; i++) {
		L[i] = A[l + i];
	}
	for(int i = 0; i < n2; i++) {
		R[i] = A[m + i + 1];
	}

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		A[k++] = L[i] <= R[j] ? L[i++] : R[j++];
	}

	while(i < n1) A[k++] = L[i++];
	while(j < n2) A[k++] = R[j++];

}

void MergeSort(int A[], int l, int r) {
	if(l < r) {
		int mid = l + (r - l)/2;

		MergeSort(A, l, mid);
		MergeSort(A, mid+1, r);
		merge(A, l, mid, r);
	}
}

	
