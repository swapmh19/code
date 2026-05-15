#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#define NO_OF_CHARS 256

int getNextState(const std::string& pat, int M, int state, int x) {
    if (state < M && x == (unsigned char)pat[state]) return state + 1;
    for (int ns = state; ns > 0; ns--) {
        if ((unsigned char)pat[ns - 1] == x) {
            int i;
            for (i = 0; i < ns - 1; i++)
                if (pat[i] != pat[state - ns + 1 + i]) break;
            if (i == ns - 1) return ns;
        }
    }
    return 0;
}

void computeTF(const std::string& pat, int M, std::vector<std::vector<int>>& TF) {
    for (int state = 0; state <= M; state++)
        for (int x = 0; x < NO_OF_CHARS; x++)
            TF[state][x] = getNextState(pat, M, state, x);
}

void search(const std::string& pat, const std::string& txt) {
    int M = pat.length();
    int N = txt.length();
    std::vector<std::vector<int>> TF(M + 1, std::vector<int>(NO_OF_CHARS));
    computeTF(pat, M, TF);
    int state = 0;
    for (int i = 0; i < N; i++) {
        state = TF[state][(unsigned char)txt[i]];
        if (state == M) std::cout << "Pattern found at index " << i - M + 1 << std::endl;
    }
}

int main() {
    std::string txt, pat;
    std::cout << "Enter text: ";
    std::cin >> txt;
    std::cout << "Enter pattern: ";
    std::cin >> pat;

    clock_t start = clock();
    search(pat, txt);
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
