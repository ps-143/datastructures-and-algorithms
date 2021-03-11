#include <iostream>
using namespace std;

int partition(int A[], int l, int r) {
    int p = A[l];
    int i = l, j = r;
    while(i <= j) {
        if(A[i] <= p) {
            i++;
        }
        else {
            swap(A[i], A[j]);
            j--;
        }
    }
    swap(A[l], A[i-1]);
    return i - 1;
}

void quickSort(int A[], int l, int r) {
    if(r <= l) {
        return;
    }
    int q = partition(A, l, r);

    quickSort(A, l, q - 1);
    quickSort(A, q + 1, r);
}

int main() {
    int A[] = {5, 1, 8, 9, 2, 3, 6, 0, -1, -7, -12};
    int n = sizeof(A)/sizeof(int);
    cout << n << endl;
    quickSort(A, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
