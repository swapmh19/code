#include <iostream>
#include <vector>
#include <ctime>
#include <climits>

int bruteForceMaxSubarray(const std::vector<int>& arr, int n) {
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) max_sum = current_sum;
        }
    }
    return max_sum;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    clock_t start = clock();
    int max_sum = bruteForceMaxSubarray(arr, n);
    clock_t end = clock();

    std::cout << "Maximum contiguous sum (Brute Force) is " << max_sum << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Brute Force method checks all possible subarrays (i, j) and calculates 
their sums to find the maximum.
Complexity: O(n^2)
Recurrence Relation: T(n) = O(n^2)
*/
