#include <stdio.h>
#include <limits.h>
#include <time.h>

#define V 10

int n, dist[V][V];
int min_path = INT_MAX;

void tspBacktrack(int curr_pos, int count, int cost, int visited[]) {
    if (count == n && dist[curr_pos][0] > 0) {
        if (cost + dist[curr_pos][0] < min_path)
            min_path = cost + dist[curr_pos][0];
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[curr_pos][i] > 0) {
            visited[i] = 1;
            tspBacktrack(i, count + 1, cost + dist[curr_pos][i], visited);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities (max 10): ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &dist[i][j]);

    int visited[V] = {0};
    visited[0] = 1;

    clock_t start = clock();
    tspBacktrack(0, 1, 0, visited);
    clock_t end = clock();

    printf("Min distance (Backtracking): %d\n", min_path);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Backtracking method for TSP explores all possible permutations of 
cities to find the shortest Hamiltonian cycle. It visits each city 
one by one and backtracks when all paths from a city are explored.
Complexity: O(n!)
Recurrence Relation: T(n) = n * T(n-1) + O(n)
*/
