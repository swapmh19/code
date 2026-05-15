/*
============================================================
 EXP 3: Quick Sort (Divide & Conquer)
 TRICK TO REMEMBER:
   Pick a PIVOT → put smaller elements LEFT, larger RIGHT
   (this is called PARTITIONING)
   Recursively quicksort left and right parts
   The pivot is in its FINAL POSITION after partition!
============================================================
*/
#include <stdio.h>
#include <time.h>

// Places pivot at correct position; returns pivot index
// Elements < pivot go left, elements > pivot go right
int partition(int a[], int low, int high)
{
    int pivot = a[high]; // choose last element as pivot
    int i = low - 1;     // i tracks boundary of "smaller elements" region

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        { // if current element belongs on left side
            i++;
            // Manual swap
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // place pivot between left and right regions
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1; // pivot's final index
}

void quickSort(int a[], int low, int high)
{
    if (low >= high)
        return; // BASE CASE: 0 or 1 element

    int pi = partition(a, low, high); // pi = pivot's final correct index
    quickSort(a, low, pi - 1);        // sort left of pivot
    quickSort(a, pi + 1, high);       // sort right of pivot

    // NOTE: pivot itself is NOT included in either recursive call
    //       because it's already in its correct position!
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

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
    if (n > 1)
        quickSort(a, 0, n - 1);
    clock_t e = clock();

    printf("Sorted  : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Time: %.8f sec\n", (double)(e - s) / CLOCKS_PER_SEC);

    /*
    COMPLEXITY:
    Best/Average → O(n log n)  [pivot splits array roughly in half]
    Worst        → O(n²)       [pivot is always smallest/largest, e.g. sorted array]
    Space        → O(log n)    [recursion stack, in-place sort]

    QUICK vs MERGE:
    Quick → faster in practice (cache-friendly, in-place) but O(n²) worst
    Merge → guaranteed O(n log n) but needs O(n) extra space
    */
    return 0;
}
/*
Concept:
Quick Sort: Divide and conquer sorting algorithm using a pivot.
Complexity: O(n log n) expected, O(n^2) worst
Recurrence Relation: T(n) = 2T(n/2) + O(n) expected
*/
