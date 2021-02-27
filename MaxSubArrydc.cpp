#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int maxSubCross(int *arr, int l, int r, int m) {
    int lsum = INT_MIN;
    int sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        lsum = max(lsum, sum);
    }

    int rsum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rsum = max(rsum, sum);
    }

    return lsum + rsum;
}

int maxSubArr(int *arr, int l, int r) {
    if (l >= r) {
        return arr[l];
    }
    int m = (l + r) / 2;
    int ms = INT_MIN;
    int ls = maxSubArr(arr, l, m), rs = maxSubArr(arr, m + 1, r),
        cs = maxSubCross(arr, l, r, m);
    if (ls > ms) {
        ms = ls;
    }
    if (rs > ms) {
        ms = rs;
    }
    if (cs > ms) {
        ms = cs;
    }
    return ms;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSubArr(arr, 0, n - 1) << endl;
    return 0;
}
