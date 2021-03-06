#include <bits/stdc++.h>
using namespace std;
#define LEFT(i) ((i+1)<<1) - 1
#define RIGHT(i) (i+1)<<1

bool isMaxHeap(int A[], int n) {
    int i = 0;
    bool f = true;
    while(LEFT(i) < n) {
        if(!( A[LEFT(i)] <= A[i] )) {
            f = false;
            break;
        }
        if(RIGHT(i) < n && !( A[RIGHT(i)] <= A[i] )) {
            f = false;
            break;
        }
        i++;
    }
    return f;
}

int main() {
    int a[] = {23, 17, 14, 7, 13, 10, 1, 5, 6, 12};
    int x[] = {10, 4, 7, 5, 3, 6, 2};
    cout << sizeof(a) << endl;
    cout << isMaxHeap(a, sizeof(a)/sizeof(int)) << endl;
    cout << isMaxHeap(x, sizeof(x)/sizeof(int)) << endl;
    return 0;
}

