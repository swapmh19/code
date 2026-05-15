#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int matrixChainOrder(const std::vector<int>& p, int n) {
    std::vector<std::vector<int>> m(n, std::vector<int>(n));
    for (int i = 1; i < n; i++) m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    std::cout << "Enter number of matrices: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> p(n + 1);
    std::cout << "Enter dimensions (p0, p1, ..., pn): ";
    for (int i = 0; i <= n; i++) std::cin >> p[i];

    clock_t start = clock();
    int min_cost = matrixChainOrder(p, n + 1);
    clock_t end = clock();

    std::cout << "Minimum number of multiplications is " << min_cost << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Matrix Chain Multiplication finds the most efficient way to multiply a 
sequence of matrices. It uses Dynamic Programming to store results of 
subproblems (minimum cost to multiply a range of matrices).
Complexity: O(n^3)
Recurrence Relation: T(i, j) = min_{i<=k<j} {T(i, k) + T(k+1, j) + p_{i-1}*p_k*p_j}
*/
