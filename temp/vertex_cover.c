#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define V 20

void printVertexCover(int graph[V][V]) {
    bool visited[V] = {false};
    printf("Vertex Cover: ");
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[u] && !visited[v]) {
                visited[u] = true;
                visited[v] = true;
                printf("%d %d ", u, v);
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {0};
    srand(time(0));
    // Generate a random graph with at least 20 vertices
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (rand() % 4 == 0) { // 25% chance of an edge
                graph[i][j] = graph[j][i] = 1;
            }
        }
    }

    clock_t start = clock();
    printVertexCover(graph);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Vertex Cover Problem is NP-hard. The Approximation Algorithm (Greedy) 
works by picking an edge (u, v), adding both u and v to the cover, 
and removing all edges incident to u or v.
Complexity: O(V + E)
Recurrence Relation: T(n) = O(V + E)
*/
