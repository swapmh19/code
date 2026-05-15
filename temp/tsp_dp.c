#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 10

int n, dist[MAX][MAX];
int visited_all;
int memo[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == visited_all) return dist[pos][0];
    if (memo[mask][pos] != -1) return memo[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) ans = newAns;
        }
    }
    return memo[mask][pos] = ans;
}

int main() {
    printf("Enter number of cities (max 10): ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &dist[i][j]);

    visited_all = (1 << n) - 1;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++) memo[i][j] = -1;

    clock_t start = clock();
    int min_dist = tsp(1, 0);
    clock_t end = clock();

    printf("Min distance: %d\n", min_dist);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Travelling Salesman Problem (TSP) finds the shortest possible route 
that visits each city exactly once and returns to the origin. 
This implementation uses Dynamic Programming with Bitmasking.
Complexity: O(n^2 * 2^n)
Recurrence Relation: cost(mask, pos) = min_{city} {dist[pos][city] + cost(mask | (1 << city), city)}
*/
