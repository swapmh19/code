#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = std::max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
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
    int res = knapsack(W, wt, val, n);
    clock_t end = clock();

    std::cout << "Max value: " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The 0/1 Knapsack Problem is a classic Dynamic Programming problem. 
Given weights and values of items, we want to maximize the total value 
in a knapsack of capacity W. Each item can either be taken (1) or not (0).
Complexity: O(n*W)
Recurrence Relation: K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
*/
