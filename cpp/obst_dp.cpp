#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int sum(const std::vector<int>& freq, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

int optimalSearchTree(const std::vector<int>& keys, const std::vector<int>& freq, int n) {
    std::vector<std::vector<int>> cost(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int s = sum(freq, i, j);
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) + s;
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    std::cout << "Enter number of keys: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> keys(n), freq(n);
    std::cout << "Enter keys and frequencies:" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> keys[i] >> freq[i];

    clock_t start = clock();
    int res = optimalSearchTree(keys, freq, n);
    clock_t end = clock();

    std::cout << "Cost of OBST: " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Optimal Binary Search Tree (OBST) problem finds a binary search tree 
for a given set of keys and their search frequencies such that the 
average search cost is minimized. It uses Dynamic Programming.
Complexity: O(n^3)
Recurrence Relation: cost[i][j] = sum(freq, i, j) + min_{i<=r<=j} {cost[i][r-1] + cost[r+1][j]}
*/
