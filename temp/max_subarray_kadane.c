#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int kadaneMaxSubarray(int arr[], int n) {
    int max_so_far = arr[0];
    int current_max = arr[0];
    for (int i = 1; i < n; i++) {
        current_max = (arr[i] > current_max + arr[i]) ? arr[i] : current_max + arr[i];
        max_so_far = (max_so_far > current_max) ? max_so_far : current_max;
    }
    return max_so_far;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    clock_t start = clock();
    int max_sum = kadaneMaxSubarray(arr, n);
    clock_t end = clock();

    printf("Maximum contiguous sum (Kadane's) is %d\n", max_sum);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

/*
Concept:
Kadane's Algorithm is a dynamic programming approach that finds the maximum 
subarray sum in a single pass by keeping track of the max sum ending at each position.
Complexity: O(n)
Recurrence Relation: T(n) = T(n-1) + O(1)
*/
