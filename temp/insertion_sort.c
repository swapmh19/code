#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    clock_t end = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}

/*
Concept:
Insertion Sort works by taking one element at a time from the unsorted part 
and inserting it into its correct position in the sorted part.
It is similar to how we sort playing cards in our hands.
Complexity: O(n^2)
Recurrence Relation: T(n) = T(n-1) + O(n)
*/
