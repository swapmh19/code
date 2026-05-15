#include <stdio.h>
#include <time.h>

int solve(int board[8], int row)
{
    int col, i;

    // If all queens are placed
    if (row == 8)
    {
        return 1;
    }

    // Try placing queen in each column
    for (col = 0; col < 8; col++)
    {
        int safe = 1;

        // Check previous queens
        for (i = 0; i < row; i++)
        {
            // Same column or diagonal
            if (board[i] == col ||
                (i - board[i] == row - col) ||
                (i + board[i] == row + col))
            {
                safe = 0;
                break;
            }
        }

        // Place queen if safe
        if (safe)
        {
            board[row] = col;

            // Recur for next row
            if (solve(board, row + 1))
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int board[8];
    int i, j;

    clock_t start, end;
    double time_taken;

    start = clock();

    if (solve(board, 0))
    {
        printf("Solution for 8 Queens Problem:\n\n");

        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution found.\n");
    }

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
N-Queens Problem: Uses Backtracking to place N queens on an NxN chessboard.
Complexity: O(N!)
Recurrence Relation: None
*/
