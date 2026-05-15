/*
============================================================
 Bellman Ford Algorithm (Single Source Shortest Path)
 Finds shortest distance from a source vertex to all vertices
 Also calculates running time using time() function
============================================================
*/

#include <stdio.h>
#include <time.h>

#define INF 99999

// ---------------- Bellman Ford Function ----------------
void bellmanFord(int edges[][3], int V, int E, int source)
{
    int dist[100];
    int i, j, u, v, w;

    // Initialize distances
    for (i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (j = 0; j < E; j++)
    {
        u = edges[j][0];
        v = edges[j][1];
        w = edges[j][2];

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("\nGraph contains negative weight cycle\n");
            return;
        }
    }

    // Print shortest distances
    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < V; i++)
    {
        printf("Vertex %d -> Distance = %d\n", i, dist[i]);
    }
}

// ---------------- Main Function ----------------
int main()
{
    int V, E, i, source;
    int edges[100][3];

    clock_t start, end;
    double time_taken;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (source destination weight):\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i][0],
              &edges[i][1],
              &edges[i][2]);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Start time
    start = clock();

    bellmanFord(edges, V, E, source);

    // End time
    end = clock();

    // Time in microseconds
    time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nRunning Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Bellman-Ford Algorithm: Finds shortest paths from a single source to all vertices handling negative weights.
Complexity: O(V*E)
Recurrence Relation: None
*/
