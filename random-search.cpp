#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int random_search(int A[], int n, int e) {
    int *h, c = 0, mc = (n * (n + 1)) / 2, i, ind = -1;
    h = new int[n];
    memset(h, 0, sizeof(int));
    while(c < mc) {
        i = random() % n;
        if(A[i] == e) {
            ind = i;
            break;
        }
        else if (h[i] == 0)
         c++;
        else h[i]++;
    }
    return ind;
}

int main() {
    int n = 10, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    cout << random_search(a, n, 10) << endl;
    return 0;
}

