#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

int lcsRecursive(const std::string& X, const std::string& Y, int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcsRecursive(X, Y, m - 1, n - 1);
    else
        return std::max(lcsRecursive(X, Y, m, n - 1), lcsRecursive(X, Y, m - 1, n));
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
    int length = lcsRecursive(X, Y, m, n);
    clock_t end = clock();

    std::cout << "Length of LCS (Recursive) is " << length << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
