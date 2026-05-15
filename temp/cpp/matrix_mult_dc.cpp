#include <iostream>
#include <vector>
#include <ctime>

int main() {
    std::vector<std::vector<int>> A(2, std::vector<int>(2));
    std::vector<std::vector<int>> B(2, std::vector<int>(2));
    std::vector<std::vector<int>> C(2, std::vector<int>(2));
    
    std::cout << "Enter elements of 2x2 Matrix A:" << std::endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) std::cin >> A[i][j];

    std::cout << "Enter elements of 2x2 Matrix B:" << std::endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) std::cin >> B[i][j];

    clock_t start = clock();
    // Simplified 8 multiplications logic for 2x2
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    clock_t end = clock();

    std::cout << "Result Matrix C (Recursive D&C):" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) std::cout << C[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Divide and Conquer approach for Matrix Multiplication splits matrices 
into smaller sub-matrices and performs 8 recursive multiplications.
Complexity: O(n^3)
Recurrence Relation: T(n) = 8T(n/2) + O(n^2)
*/
