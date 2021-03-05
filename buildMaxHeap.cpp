#include <bits/stdc++.h>
using namespace std;
#define LEFT(i) i<<1
#define RIGHT(i) ( i<<1 ) + 1
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int A[], int i, int n) {
    while(LEFT(i) < n) {
        if(A[i] < LEFT(i)) {
            swap(&A[i], &A[LEFT(i)]);
            i = LEFT(i);
        }
        else if(RIGHT(i) < n && A[RIGHT(i)] > A[i]) {
            swap(&A[i], &A[RIGHT(i)]);
            i = RIGHT(i);
        }
        else {
            break;
        }
    }
}

void maxHeap(int A[], int n) {
    for(int i = n/2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

int main() {
    int a[] = {5, 4, 3, 3, 5};
    maxHeap(a, 5);
    for(int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

