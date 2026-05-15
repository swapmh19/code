#include <stdio.h>
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsackRecursive(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W)
        return knapsackRecursive(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapsackRecursive(W - wt[n - 1], wt, val, n - 1),
                   knapsackRecursive(W, wt, val, n - 1));
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
    int res = knapsackRecursive(W, wt, val, n);
    clock_t end = clock();

    printf("Max value (Recursive): %d\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Recursive method for 0/1 Knapsack explores every combination of items 
(either including or excluding each item) to find the maximum value.
Complexity: O(2^n)
Recurrence Relation: T(n, W) = T(n-1, W) + T(n-1, W-w_n) + O(1)
*/
