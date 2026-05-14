#include <iostream>
#include <vector>
#include <ctime>

void multiply(int n, const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int n;
    std::cout << "Enter size of square matrix (n): ";
    if (!(std::cin >> n)) return 0;

    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    std::vector<std::vector<int>> B(n, std::vector<int>(n));
    std::vector<std::vector<int>> C(n, std::vector<int>(n));

    std::cout << "Enter elements of Matrix A:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> A[i][j];

    std::cout << "Enter elements of Matrix B:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> B[i][j];

    clock_t start = clock();
    multiply(n, A, B, C);
    clock_t end = clock();

    std::cout << "Result Matrix C:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << C[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Standard Matrix Multiplication involves multiplying rows of the first matrix 
by columns of the second matrix. It is the basic approach before 
exploring more complex Divide and Conquer algorithms.
Complexity: O(n^3)
Recurrence Relation: T(n) = O(n^3)
*/
