#include <stdio.h>
#include <limits.h>
#include <time.h>

void optimalBST(int freq[], int n)
{
    int cost[n][n];
    int i, j, k, length;

    // Cost for single key
    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Build table using DP
    for (length = 2; length <= n; length++)
    {
        for (i = 0; i <= n - length; i++)
        {
            j = i + length - 1;
            cost[i][j] = INT_MAX;

            int sum = 0;
            for (k = i; k <= j; k++)
                sum += freq[k];

            // Try each key as root
            for (k = i; k <= j; k++)
            {
                int left = (k > i) ? cost[i][k - 1] : 0;
                int right = (k < j) ? cost[k + 1][j] : 0;

                int total = left + right + sum;

                if (total < cost[i][j])
                    cost[i][j] = total;
            }
        }
    }

    printf("Minimum Cost of Optimal BST = %d\n", cost[0][n - 1]);
}

int main()
{
    int n, i;
    int freq[100];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    clock_t start, end;

    start = clock();

    optimalBST(freq, n);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
Binary Search Tree Operations: Basic BST operations like insertion and traversal.
Complexity: O(h) where h is height
Recurrence Relation: None
*/
