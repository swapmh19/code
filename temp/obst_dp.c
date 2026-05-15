#include <stdio.h>
#include <limits.h>
#include <time.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];
    for (int i = 0; i < n; i++) cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int s = sum(freq, i, j);
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) + s;
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    int keys[n], freq[n];
    printf("Enter keys and frequencies:\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &keys[i], &freq[i]);

    clock_t start = clock();
    int res = optimalSearchTree(keys, freq, n);
    clock_t end = clock();

    printf("Cost of OBST: %d\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Optimal Binary Search Tree (OBST) problem finds a binary search tree 
for a given set of keys and their search frequencies such that the 
average search cost is minimized. It uses Dynamic Programming.
Complexity: O(n^3)
Recurrence Relation: cost[i][j] = sum(freq, i, j) + min_{i<=r<=j} {cost[i][r-1] + cost[r+1][j]}
*/
