#include <stdio.h>
#include <limits.h>
#include <time.h>

struct Edge { int src, dest, weight; };

void bellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Edge edges[E];
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    clock_t start = clock();
    bellmanFord(V, E, edges, src);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
Bellman-Ford Algorithm finds the shortest path from a source to all other 
vertices in a weighted graph. Unlike Dijkstra, it can handle negative 
edge weights and detect negative weight cycles.
Complexity: O(V*E)
Recurrence Relation: T(i, v) = min(T(i-1, v), min_{u} {T(i-1, u) + w(u, v)})
*/
