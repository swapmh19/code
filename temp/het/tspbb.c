#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 10
#define INF 99999

// Function for TSP using Branch and Bound
int tsp(int graph[MAX][MAX], int visited[MAX], int currPos,
        int n, int count, int cost, int *ans)
{
    // If all cities are visited and path exists to starting city
    if (count == n && graph[currPos][0] > 0)
    {
        if (cost + graph[currPos][0] < *ans)
        {
            *ans = cost + graph[currPos][0];
        }
        return *ans;
    }

    // Try visiting every unvisited city
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && graph[currPos][i] > 0)
        {
            int newCost = cost + graph[currPos][i];

            // Branch and Bound condition
            if (newCost < *ans)
            {
                visited[i] = 1;

                tsp(graph, visited, i, n, count + 1, newCost, ans);

                visited[i] = 0; // Backtrack
            }
        }
    }

    return *ans;
}

int main()
{
    int n;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int ans = INF;

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

    visited[0] = 1; // Start from city 0

    clock_t start, end;

    start = clock();

    int minCost = tsp(graph, visited, 0, n, 1, 0, &ans);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMinimum Traveling Cost = %d\n", minCost);

    printf("Execution Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
Travelling Salesperson (B&B): Uses Branch and Bound to find min cost tour.
Complexity: O(n!) worst
Recurrence Relation: None
*/
