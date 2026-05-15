#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 10
#define INF 99999

// Function to solve TSP using Dynamic Programming
int tsp(int graph[MAX][MAX], int dp[1 << MAX][MAX], int mask, int pos, int n)
{
    // If all cities are visited, return to starting city
    if (mask == (1 << n) - 1)
    {
        return graph[pos][0];
    }

    // If already calculated
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INF;

    // Visit all unvisited cities
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] +
                         tsp(graph, dp, mask | (1 << city), city, n);

            if (newAns < ans)
            {
                ans = newAns;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int n;
    int graph[MAX][MAX];
    int dp[1 << MAX][MAX];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize DP table
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    clock_t start, end;

    start = clock();

    int minCost = tsp(graph, dp, 1, 0, n);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMinimum Traveling Cost = %d\n", minCost);

    printf("Execution Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
Travelling Salesperson (DP): Uses DP with bitmasking to solve TSP.
Complexity: O(n^2 * 2^n)
Recurrence Relation: None
*/
