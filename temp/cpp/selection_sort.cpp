#include <iostream>
#include <vector>
#include <ctime>

void selectionSort(std::vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> arr(n);
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\nTime taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Selection Sort works by repeatedly finding the minimum element from the 
unsorted part and putting it at the beginning.
Complexity: O(n^2)
Recurrence Relation: T(n) = T(n-1) + O(n)
*/
