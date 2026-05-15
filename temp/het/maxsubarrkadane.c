/*
============================================================
 EXP: Maximum Subarray Sum using Kadane's Algorithm
============================================================
*/

#include <stdio.h>
#include <limits.h>
#include <time.h>

// -------- Kadane Function --------
int kadane(int a[], int n)
{
    int max_so_far = INT_MIN;
    int current_sum = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += a[i];

        if (current_sum > max_so_far)
            max_so_far = current_sum;

        if (current_sum < 0)
            current_sum = 0;
    }

    return max_so_far;
}

// -------- Main Function --------
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start, end;

    start = clock();

    int maxSum = kadane(a, n);

    end = clock();

    double time_taken;
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    printf("\nMaximum Subarray Sum = %d\n", maxSum);
    printf("Execution Time = %.2f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Kadane's Algorithm: Finds maximum subarray sum using dynamic programming.
Complexity: O(n)
Recurrence Relation: None
*/
