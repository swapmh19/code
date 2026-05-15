#include <stdio.h>
#include <string.h>
#include <time.h>

void KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    // Build LPS array
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    // KMP Searching
    i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char text[1000], pattern[1000];

    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter Pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    clock_t start, end;

    start = clock();

    KMP(text, pattern);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    printf("Running Time = %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
KMP String Matching: String matching using an LPS array to avoid redundant checks.
Complexity: O(n + m)
Recurrence Relation: None
*/
