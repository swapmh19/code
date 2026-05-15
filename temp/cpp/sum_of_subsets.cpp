#include <iostream>
#include <vector>
#include <ctime>

void subsetSum(const std::vector<int>& set, std::vector<int>& subset, int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        std::cout << "Subset found: ";
        for (int i = 0; i < subSize; i++) std::cout << subset[i] << " ";
        std::cout << std::endl;
        return;
    }
    for (int i = nodeCount; i < n; i++) {
        subset[subSize] = set[i];
        subsetSum(set, subset, n, subSize + 1, total + set[i], i + 1, sum);
    }
}

int main() {
    int n, sum;
    std::cout << "Enter number of elements in set: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> set(n), subset(n);
    std::cout << "Enter elements of set: ";
    for (int i = 0; i < n; i++) std::cin >> set[i];
    std::cout << "Enter target sum: ";
    std::cin >> sum;

    clock_t start = clock();
    subsetSum(set, subset, n, 0, 0, 0, sum);
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Sum of Subsets problem finds all subsets of a given set whose elements 
sum up to a target value. It uses Backtracking to explore the state 
space tree and prunes branches that cannot lead to a solution.
Complexity: O(2^n)
Recurrence Relation: T(n) = 2T(n-1) + O(1)
*/
