#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int min(int x, int y) { return (x < y) ? x : y; }

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSortIterative(int arr[], int n) {
    int curr_size;
    int left_start;
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    clock_t start = clock();
    mergeSortIterative(arr, n);
    clock_t end = clock();

    printf("Sorted array (Iterative): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

/*
Concept:
The Iterative Merge Sort (Bottom-Up) starts by merging subarrays of size 1, 
then size 2, then size 4, and so on, until the entire array is sorted.
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n)
*/
