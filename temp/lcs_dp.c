#include <stdio.h>
#include <string.h>
#include <time.h>

int max(int a, int b) { return (a > b) ? a : b; }

int lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    char X[100], Y[100];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    clock_t start = clock();
    int length = lcs(X, Y, m, n);
    clock_t end = clock();

    printf("Length of LCS is %d\n", length);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
Longest Common Subsequence (LCS) finds the longest subsequence present in 
two sequences in the same relative order. It uses Dynamic Programming 
to build a table of LCS lengths for all prefixes of the two strings.
Complexity: O(m*n)
Recurrence Relation: L[i][j] = L[i-1][j-1] + 1 if X[i]==Y[j], else max(L[i-1][j], L[i][j-1])
*/
