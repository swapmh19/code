#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

int lcs(const std::string& X, const std::string& Y, int m, int n) {
    std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    std::string X, Y;
    std::cout << "Enter first string: ";
    std::cin >> X;
    std::cout << "Enter second string: ";
    std::cin >> Y;

    int m = X.length();
    int n = Y.length();

    clock_t start = clock();
    int length = lcs(X, Y, m, n);
    clock_t end = clock();

    std::cout << "Length of LCS is " << length << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
