#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define V 100

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[n];
    bool sptSet[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int n, graph[V][V];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    clock_t start = clock();
    dijkstra(graph, src, n);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
Dijkstra's Algorithm finds the shortest path from a source vertex to all 
other vertices in a weighted graph with non-negative edge weights. 
It uses a greedy approach by always picking the nearest unvisited vertex.
Complexity: O(V^2) for adjacency matrix.
Recurrence Relation: T(V) = T(V-1) + O(V)
*/
