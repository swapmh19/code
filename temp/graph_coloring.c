#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define V 100

bool isSafe(int v, int graph[V][V], int color[], int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == color[i]) return false;
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v, int n) {
    if (v == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, n)) return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, graph[V][V], m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
    printf("Enter number of colors: ");
    scanf("%d", &m);

    int color[n];
    for (int i = 0; i < n; i++) color[i] = 0;

    clock_t start = clock();
    if (graphColoringUtil(graph, m, color, 0, n)) {
        printf("Colors assigned: ");
        for (int i = 0; i < n; i++) printf("%d ", color[i]);
        printf("\n");
    } else printf("Solution does not exist\n");
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
Concept:
The Graph Coloring Problem assigns colors to vertices such that no two 
adjacent vertices have the same color. It uses Backtracking to try 
different colors for each vertex and backtrack if no color is valid.
Complexity: O(m^V)
Recurrence Relation: T(n) = m * T(n-1) + O(n)
*/
