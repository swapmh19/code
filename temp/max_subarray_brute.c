#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bruteForceMaxSubarray(int arr[], int n) {
    int max_sum = -1e9; // Smallest possible int
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) max_sum = current_sum;
        }
    }
    return max_sum;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    clock_t start = clock();
    int max_sum = bruteForceMaxSubarray(arr, n);
    clock_t end = clock();

    printf("Maximum contiguous sum (Brute Force) is %d\n", max_sum);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

/*
Concept:
The Brute Force method checks all possible subarrays (i, j) and calculates 
their sums to find the maximum.
Complexity: O(n^2)
Recurrence Relation: T(n) = O(n^2)
*/
