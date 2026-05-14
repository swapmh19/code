#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int sum(const std::vector<int>& freq, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

int obstRecursive(const std::vector<int>& freq, int i, int j) {
    if (j < i) return 0;
    if (j == i) return freq[i];
    int fsum = sum(freq, i, j);
    int min_cost = INT_MAX;
    for (int r = i; r <= j; r++) {
        int cost = obstRecursive(freq, i, r - 1) + obstRecursive(freq, r + 1, j);
        if (cost < min_cost) min_cost = cost;
    }
    return min_cost + fsum;
}

int main() {
    int n;
    std::cout << "Enter number of keys: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> keys(n), freq(n);
    std::cout << "Enter keys and frequencies:" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> keys[i] >> freq[i];

    clock_t start = clock();
    int res = obstRecursive(freq, 0, n - 1);
    clock_t end = clock();

    std::cout << "Cost of OBST (Recursive): " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Recursive method for Optimal Binary Search Tree tries every key as 
the root and recursively finds the cost of left and right subtrees.
Complexity: O(2^n)
Recurrence Relation: T(n) = sum_{k=1}^{n} [T(k-1) + T(n-k)] + O(n)
*/
