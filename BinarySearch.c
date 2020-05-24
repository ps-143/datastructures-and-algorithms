#include <stdio.h>

int BinarySearch(int A[], int l, int r, int element) {
	int index;
	int mid = l + (r - l)/2;
	if(A[l] == element) {
		index = l;
	}
	else if(element <= A[mid]) 
		index = BinarySearch(A, l, mid, element);
	else
		index = BinarySearch(A, mid+1, r, element);
	return index;
}

int main() {
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d\n", BinarySearch(A, 0, 8, 4));
	return 0;
}

