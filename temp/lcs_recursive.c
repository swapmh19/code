#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int lcsRecursive(char* X, char* Y, int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcsRecursive(X, Y, m - 1, n - 1);
    else
        return max(lcsRecursive(X, Y, m, n - 1), lcsRecursive(X, Y, m - 1, n));
}

int main() {
    char X[20], Y[20];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    clock_t start = clock();
    int length = lcsRecursive(X, Y, m, n);
    clock_t end = clock();

    printf("Length of LCS (Recursive) is %d\n", length);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Recursive method for LCS finds the longest common subsequence by 
comparing characters and exploring two branches: skipping a character 
from the first string or skipping a character from the second string.
Complexity: O(2^n)
Recurrence Relation: T(m, n) = T(m-1, n) + T(m, n-1) + O(1)
*/
