#include <stdio.h>
#include <limits.h>
#include <time.h>

int main()
{
    int n, i, j, k, L;

    int p[100];
    int m[100][100];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array:\n");

    // For n matrices, input size is n+1
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Start time
    clock_t start = clock();

    // Cost is 0 when multiplying one matrix
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // L = chain length
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;

            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                int q =
                    m[i][k] +
                    m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    // End time
    clock_t end = clock();

    double time_taken =
        ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;

    printf("\nMinimum number of multiplications = %d\n", m[1][n]);

    printf("Execution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Matrix Chain Multiplication: Uses DP to find the most efficient way to multiply matrices.
Complexity: O(n^3)
Recurrence Relation: None
*/
