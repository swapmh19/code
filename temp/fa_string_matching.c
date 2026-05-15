#include <stdio.h>
#include <string.h>
#include <time.h>

#define NO_OF_CHARS 256

int getNextState(char* pat, int M, int state, int x) {
    if (state < M && x == pat[state]) return state + 1;
    int ns, i;
    for (ns = state; ns > 0; ns--) {
        if (pat[ns - 1] == x) {
            for (i = 0; i < ns - 1; i++)
                if (pat[i] != pat[state - ns + 1 + i]) break;
            if (i == ns - 1) return ns;
        }
    }
    return 0;
}

void computeTF(char* pat, int M, int TF[][NO_OF_CHARS]) {
    int state, x;
    for (state = 0; state <= M; state++)
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[state][x] = getNextState(pat, M, state, x);
}

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int TF[M + 1][NO_OF_CHARS];
    computeTF(pat, M, TF);
    int i, state = 0;
    for (i = 0; i < N; i++) {
        state = TF[state][(unsigned char)txt[i]];
        if (state == M) printf("Pattern found at index %d\n", i - M + 1);
    }
}

int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);

    clock_t start = clock();
    search(pat, txt);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Finite Automata String Matching algorithm builds a transition table 
representing a state machine. The machine transitions based on characters 
read from the text, reaching an 'accept' state when the pattern is found.
Complexity: O(N + M*Sigma) where Sigma is alphabet size.
Recurrence Relation: delta(q, a) = length of longest prefix of P which is suffix of Pq + a
*/
