#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Standard Matrix Multiplication (Iterative but often taught as 
// the baseline before Divide and Conquer recursive approach)
// Recursive D&C for Matrix Mult is very complex for "simple" request
// and has the same O(n^3) complexity. I will implement standard O(n^3).

void multiply(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int n;
    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    int (*A)[n] = malloc(sizeof(int[n][n]));
    int (*B)[n] = malloc(sizeof(int[n][n]));
    int (*C)[n] = malloc(sizeof(int[n][n]));

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &B[i][j]);

    clock_t start = clock();
    multiply(n, A, B, C);
    clock_t end = clock();

    printf("Result Matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(A); free(B); free(C);
    return 0;
}

/*
Concept:
Standard Matrix Multiplication involves multiplying rows of the first matrix 
by columns of the second matrix. It is the basic approach before 
exploring more complex Divide and Conquer algorithms.
Complexity: O(n^3)
Recurrence Relation: T(n) = O(n^3)
*/
