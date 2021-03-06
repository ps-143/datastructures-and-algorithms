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

int main() {
    int a[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    int n = sizeof(a)/sizeof(int);
    cout << n << endl;
    maxHeap(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

