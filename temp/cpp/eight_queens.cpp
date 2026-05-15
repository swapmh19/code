#include <iostream>
#include <vector>
#include <ctime>

#define N 8

void printSolution(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solveNQUtil(std::vector<std::vector<int>>& board, int col) {
    if (col >= N) return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1)) return true;
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    clock_t start = clock();
    if (solveNQUtil(board, 0)) printSolution(board);
    else std::cout << "Solution does not exist" << std::endl;
    clock_t end = clock();
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    return 0;
}

/*
Concept:
The 8 Queens Problem is to place eight queens on an 8x8 chessboard 
so that no two queens threaten each other. It uses Backtracking to 
place queens one by one in columns and backtrack if a conflict occurs.
Complexity: O(N!)
Recurrence Relation: T(n) = n * T(n-1) + O(n^2)
*/
