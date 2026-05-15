#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int matrixChainRecursive(const std::vector<int>& p, int i, int j) {
    if (i == j) return 0;
    int min_cost = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = matrixChainRecursive(p, i, k) +
                    matrixChainRecursive(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];
        if (count < min_cost) min_cost = count;
    }
    return min_cost;
}

int main() {
    int n;
    std::cout << "Enter number of matrices: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> p(n + 1);
    std::cout << "Enter dimensions (p0, p1, ..., pn): ";
    for (int i = 0; i <= n; i++) std::cin >> p[i];

    clock_t start = clock();
    int min_cost = matrixChainRecursive(p, 1, n);
    clock_t end = clock();

    std::cout << "Minimum number of multiplications (Recursive) is " << min_cost << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Recursive method for Matrix Chain Multiplication explores all possible 
parenthesizations of the matrix chain. It has exponential complexity 
due to overlapping subproblems.
Complexity: O(2^n)
Recurrence Relation: T(n) = sum_{k=1}^{n-1} [T(k) + T(n-k)] + O(n)
*/
