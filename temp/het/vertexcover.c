#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

// Function to find approximate vertex cover
void vertexCover(int graph[MAX][MAX], int n)
{
    int visited[MAX] = {0};
    int i, j;

    printf("\nApproximate Vertex Cover:\n");

    // Pick edges one by one
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            for (j = 0; j < n; j++)
            {
                // If edge exists and both vertices are not visited
                if (graph[i][j] == 1 && !visited[j])
                {
                    visited[i] = 1;
                    visited[j] = 1;

                    printf("%d ", i);
                    printf("%d ", j);

                    break;
                }
            }
        }
    }

    printf("\n");
}

int main()
{
    int graph[MAX][MAX];
    int n = 20; // At least 20 vertices
    int i, j;

    clock_t start, end;
    double cpu_time;

    // Random graph generation
    srand(time(NULL));

    // Initialize graph with 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Generate random undirected graph
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // Randomly create edge (0 or 1)
            graph[i][j] = rand() % 2;
            graph[j][i] = graph[i][j];
        }
    }

    // Display adjacency matrix
    printf("Randomly Generated Graph (Adjacency Matrix):\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Start time
    start = clock();

    // Call approximation algorithm
    vertexCover(graph, n);

    // End time
    end = clock();

    // Calculate execution time
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRunning Time = %.8f seconds\n", cpu_time);

    return 0;
}
/*
Concept:
Vertex Cover (Approx): Finds an approximate vertex cover.
Complexity: O(V+E)
Recurrence Relation: None
*/
