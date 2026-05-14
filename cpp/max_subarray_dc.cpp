#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>

int maxCrossingSum(const std::vector<int>& arr, int l, int m, int h) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArraySum(const std::vector<int>& arr, int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    return std::max({maxSubArraySum(arr, l, m),
                     maxSubArraySum(arr, m + 1, h),
                     maxCrossingSum(arr, l, m, h)});
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    clock_t start = clock();
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    clock_t end = clock();

    std::cout << "Maximum contiguous sum (Divide & Conquer) is " << max_sum << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Maximum Subarray problem finds the contiguous subarray with the largest sum.
Using Divide and Conquer, we split the array into two and check:
1. Max subarray in the left half.
2. Max subarray in the right half.
3. Max subarray crossing the midpoint.
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n)
*/
