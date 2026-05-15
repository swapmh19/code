#include <stdio.h>
#include <limits.h>
#include <time.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

int obstRecursive(int freq[], int i, int j) {
    if (j < i) return 0;
    if (j == i) return freq[i];
    int fsum = sum(freq, i, j);
    int min = INT_MAX;
    for (int r = i; r <= j; r++) {
        int cost = obstRecursive(freq, i, r - 1) + obstRecursive(freq, r + 1, j);
        if (cost < min) min = cost;
    }
    return min + fsum;
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    int keys[n], freq[n];
    printf("Enter keys and frequencies:\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &keys[i], &freq[i]);

    clock_t start = clock();
    int res = obstRecursive(freq, 0, n - 1);
    clock_t end = clock();

    printf("Cost of OBST (Recursive): %d\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Recursive method for Optimal Binary Search Tree tries every key as 
the root and recursively finds the cost of left and right subtrees.
Complexity: O(2^n)
Recurrence Relation: T(n) = sum_{k=1}^{n} [T(k-1) + T(n-k)] + O(n)
*/
