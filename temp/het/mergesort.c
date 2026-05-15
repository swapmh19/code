/*
============================================================
 EXP 2: Merge Sort (Divide & Conquer)
 TRICK TO REMEMBER:
   DIVIDE array in half recursively until size=1
   CONQUER by merging two sorted halves into one sorted array
   Think of it like sorting a deck of cards by splitting into
   piles and merging them back in order
============================================================
*/
#include <stdio.h>
#include <time.h>

// Merge two sorted halves: a[l..m] and a[m+1..r]
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Pick smaller of the two and place in original array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
        }
    }

    // Copy remaining elements (only one of these runs)
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

// Recursively divide and merge
void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return; // BASE CASE: single element, already sorted

    int m = l + (r - l) / 2; // find mid (avoids overflow)

    mergeSort(a, l, m);     // sort left half
    mergeSort(a, m + 1, r); // sort right half
    merge(a, l, m, r);      // merge both sorted halves
}

int main()
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1)
        return 1;

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    clock_t s = clock();
    mergeSort(a, 0, n - 1);
    clock_t e = clock();

    printf("Sorted  : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Time: %.8f sec\n", (double)(e - s) / CLOCKS_PER_SEC);

    /*
    COMPLEXITY:
    Time  → O(n log n) in ALL cases (best, avg, worst)
    Space → O(n) for temporary arrays during merge

    WHY log n? → Array is split in HALF each time
                 so recursion depth = log₂(n) levels
    WHY n?     → At each level, total work = n comparisons
    ∴ Total    → n × log n
    */
    return 0;
}
/*
Concept:
Merge Sort: Stable divide and conquer sorting algorithm.
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n)
*/
