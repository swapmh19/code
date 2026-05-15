#include <stdio.h>
#include <time.h>

int knapsack(int n, int wt[], int val[], int W)
{
    int i, w;
    int dp[100][100];

    // Build DP table
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W, i;
    int wt[100], val[100];
    int result;

    clock_t start, end;
    double time_taken;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    start = clock();

    result = knapsack(n, wt, val, W);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMaximum Profit = %d\n", result);
    printf("Running Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
0/1 Knapsack (DP): Finds max value within weight limit using dynamic programming.
Complexity: O(nW)
Recurrence Relation: None
*/
