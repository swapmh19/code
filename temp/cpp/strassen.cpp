#include <iostream>
#include <vector>
#include <ctime>

// Strassen's Algorithm simplified for 2x2 to show the concept
// General Strassen for NxN is very large; using 2x2 for simplicity.

void strassen2x2(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int m2 = (A[1][0] + A[1][1]) * B[0][0];
    int m3 = A[0][0] * (B[0][1] - B[1][1]);
    int m4 = A[1][1] * (B[1][0] - B[0][0]);
    int m5 = (A[0][0] + A[0][1]) * B[1][1];
    int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

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
    strassen2x2(A, B, C);
    clock_t end = clock();

    std::cout << "Result Matrix C:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) std::cout << C[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Strassen's Algorithm is a Divide and Conquer approach for matrix multiplication 
that reduces the number of recursive multiplications from 8 to 7.
Complexity: O(n^2.81)
Recurrence Relation: T(n) = 7T(n/2) + O(n^2)
Note: This implementation is for 2x2 matrices to demonstrate the formulas.
*/
