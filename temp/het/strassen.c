/*
============================================================
 Strassen's Matrix Multiplication using Divide & Conquer
 Simple version for understanding

 - User enters size of matrix (n x n)
 - n should be even (2, 4, 8, ...)
 - Uses static arrays (NO malloc)
 - Measures execution time in microseconds
============================================================
*/

#include <stdio.h>
#include <time.h>

#define MAX 10

// ---------------- Function to add matrices ----------------
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// ---------------- Function to subtract matrices ----------------
void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// ---------------- Strassen Function ----------------
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size)
{
    // Base case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j;
    int newSize = size / 2;

    // Sub matrices
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

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

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, T1, newSize);
    add(B11, B22, T2, newSize);
    strassen(T1, T2, M1, newSize);

    // M2 = (A21 + A22)B11
    add(A21, A22, T1, newSize);
    strassen(T1, B11, M2, newSize);

    // M3 = A11(B12 - B22)
    subtract(B12, B22, T2, newSize);
    strassen(A11, T2, M3, newSize);

    // M4 = A22(B21 - B11)
    subtract(B21, B11, T2, newSize);
    strassen(A22, T2, M4, newSize);

    // M5 = (A11 + A12)B22
    add(A11, A12, T1, newSize);
    strassen(T1, B22, M5, newSize);

    // M6 = (A21 - A11)(B11 + B12)
    subtract(A21, A11, T1, newSize);
    add(B11, B12, T2, newSize);
    strassen(T1, T2, M6, newSize);

    // M7 = (A12 - A22)(B21 + B22)
    subtract(A12, A22, T1, newSize);
    add(B21, B22, T2, newSize);
    strassen(T1, T2, M7, newSize);

    // Calculate C11
    add(M1, M4, T1, newSize);
    subtract(T1, M5, T2, newSize);
    add(T2, M7, C11, newSize);

    // Calculate C12
    add(M3, M5, C12, newSize);

    // Calculate C21
    add(M2, M4, C21, newSize);

    // Calculate C22
    subtract(M1, M2, T1, newSize);
    add(T1, M3, T2, newSize);
    add(T2, M6, C22, newSize);

    // Combine results into final matrix
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

// ---------------- Main Function ----------------
int main()
{
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int i, j;

    clock_t start, end;
    double time_taken;

    printf("Enter size of matrix: ");
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

    // Start time
    start = clock();

    // Function call
    strassen(A, B, C, n);

    // End time
    end = clock();

    // Time in microseconds
    time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nResult Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nExecution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Strassen's Matrix Multiplication: Optimized divide and conquer matrix multiplication.
Complexity: O(n^2.81)
Recurrence Relation: T(n) = 7T(n/2) + O(n^2)
*/
