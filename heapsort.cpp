#include <bits/stdc++.h>
using namespace std;
#define LEFT(i) ((i+1)<<1) - 1
#define RIGHT(i) (i+1)<<1
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int A[], int i, int n) {
    int largest, l, r;
    l = LEFT(i);
    r = RIGHT(i);
    while(l < n) {
        if(A[l] > A[i]) largest = l;
        else largest = i;
        if(r < n && A[r] > A[largest]) largest = r;
        if(largest != i) {
            swap(&A[i], &A[largest]);
            i = largest;
            l = LEFT(i);
            r = RIGHT(i);
        }
        else break;
    }
}

void maxHeap(int A[], int n) {
    for(int i = n/2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

void heapsort(int A[], int n) {
    maxHeap(A, n);
    for(int i = n - 1; i > 0; i--) {
        swap(&A[i], &A[0]);
        heapify(A, 0, i);
    }
}

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(int);
    heapsort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

