#include "MergeSort.h"
#include "ExactSum.h"

int ExactSum(int A[], int n, int x) {
	
	MergeSort(A, 0, n-1);
	
	int l = 0, r = n-1;
	
	while(l<r) {
		if(A[l] + A[r] == x) {
			return 1;
		}
		if(A[l] + A[r] < x) l++;
		else r--;
	}

	return 0;
}

