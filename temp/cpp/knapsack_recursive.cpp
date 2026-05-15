#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int knapsackRecursive(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] > W)
        return knapsackRecursive(W, wt, val, n - 1);
    else
        return std::max(val[n - 1] + knapsackRecursive(W - wt[n - 1], wt, val, n - 1),
                        knapsackRecursive(W, wt, val, n - 1));
}

int main() {
    int n, W;
    std::cout << "Enter number of items: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> val(n), wt(n);
    std::cout << "Enter values: ";
    for (int i = 0; i < n; i++) std::cin >> val[i];
    std::cout << "Enter weights: ";
    for (int i = 0; i < n; i++) std::cin >> wt[i];
    std::cout << "Enter capacity of knapsack: ";
    std::cin >> W;

    clock_t start = clock();
    int res = knapsackRecursive(W, wt, val, n);
    clock_t end = clock();

    std::cout << "Max value (Recursive): " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Recursive method for 0/1 Knapsack explores every combination of items 
(either including or excluding each item) to find the maximum value.
Complexity: O(2^n)
Recurrence Relation: T(n, W) = T(n-1, W) + T(n-1, W-w_n) + O(1)
*/
