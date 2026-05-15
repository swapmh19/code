/*
============================================================
 Matrix Multiplication using Divide & Conquer
============================================================
*/

#include <stdio.h>
#include <time.h>

#define MAX 10

// Divide & Conquer Matrix Multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int size)
{
    int i, j;

    // Base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    // Sub matrices
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];

    int C11[MAX][MAX] = {0}, C12[MAX][MAX] = {0};
    int C21[MAX][MAX] = {0}, C22[MAX][MAX] = {0};

    int M1[MAX][MAX] = {0}, M2[MAX][MAX] = {0};

    // Divide matrices into 4 parts
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // C11 = A11*B11 + A12*B21
    multiply(A11, B11, M1, newSize);
    multiply(A12, B21, M2, newSize);

    for (i = 0; i < newSize; i++)
        for (j = 0; j < newSize; j++)
            C11[i][j] = M1[i][j] + M2[i][j];

    // C12 = A11*B12 + A12*B22
    multiply(A11, B12, M1, newSize);
    multiply(A12, B22, M2, newSize);

    for (i = 0; i < newSize; i++)
        for (j = 0; j < newSize; j++)
            C12[i][j] = M1[i][j] + M2[i][j];

    // C21 = A21*B11 + A22*B21
    multiply(A21, B11, M1, newSize);
    multiply(A22, B21, M2, newSize);

    for (i = 0; i < newSize; i++)
        for (j = 0; j < newSize; j++)
            C21[i][j] = M1[i][j] + M2[i][j];

    // C22 = A21*B12 + A22*B22
    multiply(A21, B12, M1, newSize);
    multiply(A22, B22, M2, newSize);

    for (i = 0; i < newSize; i++)
        for (j = 0; j < newSize; j++)
            C22[i][j] = M1[i][j] + M2[i][j];

    // Combine results into final matrix C
    for (i = 0; i < newSize; i++)
    {
        for (j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};
    int n, i, j;

    clock_t start, end;
    double time_taken;

    printf("Enter size of square matrix (power of 2): ");
    scanf("%d", &n);

    printf("\nEnter Matrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter Matrix B:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    start = clock();

    multiply(A, B, C, n);

    end = clock();

    printf("\nResult Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nExecution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Matrix Multiplication (D&C): Basic divide and conquer matrix multiplication.
Complexity: O(n^3)
Recurrence Relation: T(n) = 8T(n/2) + O(n^2)
*/
