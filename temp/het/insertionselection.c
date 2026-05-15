/*
============================================================
 EXP 1: Insertion Sort & Selection Sort
 TRICK TO REMEMBER:
   Insertion → Pick element, shift larger ones RIGHT, insert
   Selection → Find MIN in unsorted part, SWAP to front
============================================================
*/
#include <stdio.h>
#include <time.h>

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i]; // element to be placed
        int j = i - 1;

        // shift all elements greater than key one position right
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // place key in correct position
    }

    printf("Insertion Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i; // assume current index is minimum
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
                minIdx = j; // find actual min
        }
        // Swap elements
        int temp = a[minIdx];
        a[minIdx] = a[i];
        a[i] = temp;
    }

    printf("Selection Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int a[n], b[n]; // Creating two arrays to keep original data for both tests
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i]; // copy for the second sort
    }

    printf("\nOriginal: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    // --- Insertion Sort ---
    clock_t s1 = clock();
    insertionSort(a, n);
    clock_t e1 = clock();
    printf("Insertion Sort Time: %f sec\n\n", (double)(e1 - s1) / CLOCKS_PER_SEC);

    // --- Selection Sort ---
    clock_t s2 = clock();
    selectionSort(b, n);
    clock_t e2 = clock();
    printf("Selection Sort Time: %f sec\n", (double)(e2 - s2) / CLOCKS_PER_SEC);

    /*
    COMPLEXITY CHEAT SHEET:
    ┌──────────────────┬──────────┬──────────┬──────────┬────────┐
    │ Algorithm        │  Best    │ Average  │  Worst   │ Space  │
    ├──────────────────┼──────────┼──────────┼──────────┼────────┤
    │ Insertion Sort   │  O(n)    │  O(n²)   │  O(n²)   │  O(1)  │
    │ Selection Sort   │  O(n²)   │  O(n²)   │  O(n²)   │  O(1)  │
    └──────────────────┴──────────┴──────────┴──────────┴────────┘
    Insertion is better when array is NEARLY SORTED (best case O(n))
    Selection always does O(n²) comparisons, fewer swaps than bubble
    */
    return 0;
} 
/*
Concept:
Insertion and Selection Sort: Basic sorting algorithms.
Complexity: O(n^2)
Recurrence Relation: None
*/
