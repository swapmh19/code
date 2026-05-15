#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) if (board[row][i]) return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solveNQUtil(int board[N][N], int col) {
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
    int board[N][N] = {0};
    clock_t start = clock();
    if (solveNQUtil(board, 0)) printSolution(board);
    else printf("Solution does not exist\n");
    clock_t end = clock();
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
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
