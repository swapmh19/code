/*
============================================================
 EXP 9: Rabin-Karp String Matching Algorithm
 Finds pattern occurrences in a text using hashing
 Also calculates running time using time() function
============================================================
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256 // Number of characters
#define q 101 // Prime number for hashing

// ---------------- Rabin-Karp Function ----------------
void rabinKarp(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // Calculate h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (i = 0; i <= n - m; i++)
    {
        // If hash values match
        if (p == t)
        {
            // Check characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // Pattern found
            if (j == m)
                printf("Pattern found at position %d\n", i);
        }

        // Calculate hash for next window
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Convert negative hash to positive
            if (t < 0)
                t = t + q;
        }
    }
}

// ---------------- Main Function ----------------
int main()
{
    char text[1000], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    clock_t start, end;
    double time_taken;

    // Start time
    start = clock();

    rabinKarp(text, pattern);

    // End time
    end = clock();

    // Calculate execution time in microseconds
    time_taken = ((double)(end - start)) * 1000000 / CLOCKS_PER_SEC;

    printf("\nExecution Time: %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Rabin-Karp String Matching: String matching using hashing.
Complexity: O(n+m) avg, O(n*m) worst
Recurrence Relation: None
*/
