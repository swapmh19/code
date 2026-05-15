#include <iostream>
#include <vector>
#include <algorithm>
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

void quickSortIterative(std::vector<int>& arr, int l, int h) {
    std::vector<int> stack(h - l + 1);
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
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
    quickSortIterative(arr, 0, n - 1);
    clock_t end = clock();

    std::cout << "Sorted array (Iterative): ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\nTime taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Iterative Quick Sort uses an explicit stack to keep track of the ranges 
to be partitioned, instead of using recursive function calls.
Complexity: O(n log n) average
Recurrence Relation: T(n) = T(k) + T(n-k-1) + O(n)
*/
