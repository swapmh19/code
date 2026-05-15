#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#define d 256

void search(const std::string& pat, const std::string& txt, int q) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    for (i = 0; i < M - 1; i++) h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == M) std::cout << "Pattern found at index " << i << std::endl;
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main() {
    std::string txt, pat;
    std::cout << "Enter text: ";
    std::cin >> txt;
    std::cout << "Enter pattern: ";
    std::cin >> pat;
    int q = 101; // A prime number

    clock_t start = clock();
    search(pat, txt, q);
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Rabin-Karp Algorithm is a string matching algorithm that uses hashing 
to find any one of a set of pattern strings in a text. It calculates a 
hash for the pattern and for each window of text, comparing hashes 
before checking characters.
Complexity: O(N+M) average, O(N*M) worst case.
Recurrence Relation: H(i+1) = (d * (H(i) - T[i] * h) + T[i+M]) mod q
*/
