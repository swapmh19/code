#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }
int max3(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    return max3(maxSubArraySum(arr, l, m),
                maxSubArraySum(arr, m + 1, h),
                maxCrossingSum(arr, l, m, h));
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    clock_t start = clock();
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    clock_t end = clock();

    printf("Maximum contiguous sum (Divide & Conquer) is %d\n", max_sum);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

/*
Concept:
The Maximum Subarray problem finds the contiguous subarray with the largest sum.
Using Divide and Conquer, we split the array into two and check:
1. Max subarray in the left half.
2. Max subarray in the right half.
3. Max subarray crossing the midpoint.
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n)
*/
