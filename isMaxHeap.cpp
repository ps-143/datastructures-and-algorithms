#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int A[], int n) {
    int i = 0;
    bool f = true;
    while(2*i < n) {
        if(A[2*i] <= A[i] == false) {
            f = false;
            break;
        }
        if(2*i + 1 < n && A[2*i + 1] <= A[i] == false) {
            f = false;
            break;
        }
        i++;
    }
    return f;
}

int main() {
    int a[] = {23, 17, 14, 6, 13, 10, 1, 5, 7, 12};
    int x[] = {5, 4, 3, 3, 5};
    cout << sizeof(a) << endl;
    cout << isMaxHeap(a, sizeof(a)/sizeof(int)) << endl;
    cout << isMaxHeap(x, sizeof(x)/sizeof(int)) << endl;
    return 0;
}

