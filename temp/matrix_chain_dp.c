#include <stdio.h>
#include <time.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++) m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter dimensions (p0, p1, ..., pn): ");
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);

    clock_t start = clock();
    int min_cost = matrixChainOrder(p, n + 1);
    clock_t end = clock();

    printf("Minimum number of multiplications is %d\n", min_cost);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
Matrix Chain Multiplication finds the most efficient way to multiply a 
sequence of matrices. It uses Dynamic Programming to store results of 
subproblems (minimum cost to multiply a range of matrices).
Complexity: O(n^3)
Recurrence Relation: T(i, j) = min_{i<=k<j} {T(i, k) + T(k+1, j) + p_{i-1}*p_k*p_j}
*/
