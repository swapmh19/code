/*
============================================================
 EXP: Maximum Subarray using Divide & Conquer
============================================================

Approach:
1. Divide array into two halves
2. Find maximum subarray in:
      - Left half
      - Right half
      - Crossing middle
3. Return maximum of above three

Time Complexity:
T(n) = 2T(n/2) + O(n)
=> O(n log n)

*/

#include <stdio.h>
#include <time.h>
#include <limits.h>

// Function to find Maximum Subarray Sum
int maxSubArray(int a[], int low, int high)
{
    // Base case
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    // Maximum sum crossing mid (left side)
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += a[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    // Maximum sum crossing mid (right side)
    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    int crossSum = leftSum + rightSum;

    // Recursive calls
    int leftAns = maxSubArray(a, low, mid);
    int rightAns = maxSubArray(a, mid + 1, high);

    // Return maximum among three
    int max = leftAns;

    if (rightAns > max)
        max = rightAns;

    if (crossSum > max)
        max = crossSum;

    return max;
}

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

    int result = maxSubArray(a, 0, n - 1);

    end = clock();

    double time_taken =
        ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nMaximum Subarray Sum = %d\n", result);

    printf("Execution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Maximum Subarray (D&C): Finds the contiguous subarray with max sum using Divide & Conquer.
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n)
*/
