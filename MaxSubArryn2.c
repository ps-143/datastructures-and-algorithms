#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b

int maxSubSum(int *arr, int n) {
  int max_sum = INT_MIN;
  for (int i = 0; i < n - 1; i++) {
    int sum = arr[i];
    max_sum = max(max_sum, sum);
    for (int j = i + 1; j < n; j++) {
      sum += arr[j];
      max_sum = max(max_sum, sum);
    }
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int *arr = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", maxSubSum(arr, n));
  return 0;
}
