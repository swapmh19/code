#include <stdio.h>
#include <time.h>

int graphColoring(int graph[10][10], int color[10], int n, int m, int v)
{
    int i, c;

    // If all vertices are colored
    if (v == n)
    {
        printf("\nSolution Exists:\n");
        for (i = 0; i < n; i++)
        {
            printf("Vertex %d ---> Color %d\n", i, color[i]);
        }
        return 1;
    }

    // Try different colors
    for (c = 1; c <= m; c++)
    {
        int safe = 1;

        // Check adjacent vertices
        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && color[i] == c)
            {
                safe = 0;
                break;
            }
        }

        // Assign color if safe
        if (safe)
        {
            color[v] = c;

            // Recur for next vertex
            if (graphColoring(graph, color, n, m, v + 1))
                return 1;

            // Backtrack
            color[v] = 0;
        }
    }

    return 0;
}

int main()
{
    int graph[10][10], color[10] = {0};
    int n, m, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    clock_t start, end;

    start = clock();

    if (!graphColoring(graph, color, n, m, 0))
    {
        printf("\nNo solution exists.\n");
    }

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
Graph Coloring: Uses Backtracking to color a graph with m colors.
Complexity: O(m^V)
Recurrence Relation: None
*/
