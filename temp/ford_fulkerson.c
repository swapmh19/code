#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define V 100

bool bfs(int rGraph[V][V], int s, int t, int parent[], int n) {
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    int queue[n], head = 0, tail = 0;
    queue[tail++] = s;
    visited[s] = true;
    parent[s] = -1;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue[tail++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int graph[V][V], int s, int t, int n) {
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++) rGraph[u][v] = graph[u][v];
    int parent[n];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent, n)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow) path_flow = rGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n, graph[V][V];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter capacity matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);

    int s, t;
    printf("Enter source and sink vertex: ");
    scanf("%d %d", &s, &t);

    clock_t start = clock();
    int flow = fordFulkerson(graph, s, t, n);
    clock_t end = clock();

    printf("Max Flow: %d\n", flow);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Ford-Fulkerson Algorithm calculates the maximum flow in a flow network. 
It repeatedly finds augmenting paths using BFS (Edmonds-Karp variant) and 
increases the flow until no more paths can be found.
Complexity: O(V * E^2) with BFS.
Recurrence Relation: Flow(f) = Flow(f) + AugmentingPath(rGraph)
*/
