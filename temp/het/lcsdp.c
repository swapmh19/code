#include <stdio.h>
#include <string.h>
#include <time.h>

void lcs(char s1[], char s2[])
{
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[100][100];
    int i, j;

    // Build DP table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // Find LCS string
    int index = dp[m][n];
    char lcsString[index + 1];
    lcsString[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcsString[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLength of LCS = %d\n", dp[m][n]);
    printf("LCS = %s\n", lcsString);
}

int main()
{
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    clock_t start, end;

    start = clock();

    lcs(s1, s2);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    printf("\nExecution Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Longest Common Subsequence: Finds the longest common subsequence between two strings using DP.
Complexity: O(m*n)
Recurrence Relation: None
*/
