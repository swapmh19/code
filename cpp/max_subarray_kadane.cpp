#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int kadaneMaxSubarray(const std::vector<int>& arr, int n) {
    if (n == 0) return 0;
    int max_so_far = arr[0];
    int current_max = arr[0];
    for (int i = 1; i < n; i++) {
        current_max = std::max(arr[i], current_max + arr[i]);
        max_so_far = std::max(max_so_far, current_max);
    }
    return max_so_far;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    clock_t start = clock();
    int max_sum = kadaneMaxSubarray(arr, n);
    clock_t end = clock();

    std::cout << "Maximum contiguous sum (Kadane's) is " << max_sum << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Kadane's Algorithm is a dynamic programming approach that finds the maximum 
subarray sum in a single pass by keeping track of the max sum ending at each position.
Complexity: O(n)
Recurrence Relation: T(n) = T(n-1) + O(1)
*/
