/*
============================================================
 Dijkstra's Algorithm (Single Source Shortest Path)
 Finds shortest distance from source vertex to all vertices
============================================================
*/

#include <stdio.h>
#include <time.h>

#define INF 99999

// ---------------- Dijkstra Function ----------------
void dijkstra(int graph[20][20], int n, int source)
{
    int dist[20], visited[20];
    int i, j, min, u;

    // Initialize distances and visited array
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Find shortest path
    for (i = 0; i < n - 1; i++)
    {
        min = INF;

        // Find unvisited vertex with minimum distance
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (graph[u][j] != 0 &&
                visited[j] == 0 &&
                dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// ---------------- Main Function ----------------
int main()
{
    int graph[20][20];
    int n, i, j, source;

    clock_t start, end;
    double time_taken;

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

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Start time
    start = clock();

    dijkstra(graph, n, source);

    // End time
    end = clock();

    // Time in microseconds
    time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nExecution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Dijkstra's Algorithm: Finds shortest paths from a single source to all vertices (non-negative weights).
Complexity: O(E log V) or O(V^2)
Recurrence Relation: None
*/
