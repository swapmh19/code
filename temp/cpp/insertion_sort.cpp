#include <iostream>
#include <vector>
#include <ctime>

void insertionSort(std::vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    clock_t end = clock();

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\nTime taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Insertion Sort works by taking one element at a time from the unsorted part 
and inserting it into its correct position in the sorted part.
It is similar to how we sort playing cards in our hands.
Complexity: O(n^2)
Recurrence Relation: T(n) = T(n-1) + O(n)
*/
