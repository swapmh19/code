#include <stdio.h>
#include <string.h>
#include <time.h>

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0, j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
}

int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);

    clock_t start = clock();
    KMPSearch(pat, txt);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
KMP Algorithm (Knuth-Morris-Pratt) is a string matching algorithm that 
searches for occurrences of a pattern within a main text by employing 
the observation that when a mismatch occurs, the pattern itself embodies 
sufficient information to determine where the next match could begin.
Complexity: O(N + M)
Recurrence Relation: lps[i] = length of longest proper prefix which is also suffix
*/
