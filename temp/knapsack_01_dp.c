#include <stdio.h>
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter values: ");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    printf("Enter weights: ");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    clock_t start = clock();
    int res = knapsack(W, wt, val, n);
    clock_t end = clock();

    printf("Max value: %d\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The 0/1 Knapsack Problem is a classic Dynamic Programming problem. 
Given weights and values of items, we want to maximize the total value 
in a knapsack of capacity W. Each item can either be taken (1) or not (0).
Complexity: O(n*W)
Recurrence Relation: K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
*/
