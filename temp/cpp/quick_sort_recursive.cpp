#include <iostream>
#include <vector>
#include <ctime>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\nTime taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Quick Sort is a Divide and Conquer algorithm. It picks an element as 'pivot' 
and partitions the array around the pivot such that elements smaller than 
pivot are on the left and larger are on the right.
Complexity: O(n log n) average, O(n^2) worst case.
Recurrence Relation: T(n) = T(k) + T(n-k-1) + O(n)
*/
