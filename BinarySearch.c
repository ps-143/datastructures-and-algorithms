#include "BinarySearch.h"  

int BinarySearch(int A[], int l, int r, int element) {

	int index=-1;
	int mid = l + (r - l)/2;
	if(l<r){
		if(A[l] == element) {
			index = l;
		}
		else if(element <= A[mid]) 
			index = BinarySearch(A, l, mid, element);
		else
			index = BinarySearch(A, mid+1, r, element);
	}
	return index;
}

