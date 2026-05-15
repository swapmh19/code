#include <stdio.h>
#include <limits.h>
#include <time.h>

int matrixChainRecursive(int p[], int i, int j) {
    if (i == j) return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = matrixChainRecursive(p, i, k) +
                    matrixChainRecursive(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];
        if (count < min) min = count;
    }
    return min;
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter dimensions (p0, p1, ..., pn): ");
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);

    clock_t start = clock();
    int min_cost = matrixChainRecursive(p, 1, n);
    clock_t end = clock();

    printf("Minimum number of multiplications (Recursive) is %d\n", min_cost);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Recursive method for Matrix Chain Multiplication explores all possible 
parenthesizations of the matrix chain. It has exponential complexity 
due to overlapping subproblems.
Complexity: O(2^n)
Recurrence Relation: T(n) = sum_{k=1}^{n-1} [T(k) + T(n-k)] + O(n)
*/
