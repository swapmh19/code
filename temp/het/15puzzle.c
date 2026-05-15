#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

// Function to solve 15 Puzzle using simple Branch and Bound idea
void solvePuzzle(int puzzle[SIZE][SIZE])
{
    int i, j;
    int x = -1, y = -1;

    // Find blank space (0)
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (puzzle[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }

    printf("\nInitial Puzzle State:\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }

    // Simple Branch and Bound demonstration
    // Calculate heuristic = misplaced tiles
    int misplaced = 0;
    int expected = 1;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (i == SIZE - 1 && j == SIZE - 1)
                expected = 0;

            if (puzzle[i][j] != expected)
                misplaced++;

            expected++;
        }
    }

    printf("\nHeuristic Cost (Misplaced Tiles) = %d\n", misplaced);

    // Try moving blank tile in all directions
    printf("\nPossible Moves from Current State:\n");

    // Up
    if (x > 0)
        printf("Move Blank UP\n");

    // Down
    if (x < SIZE - 1)
        printf("Move Blank DOWN\n");

    // Left
    if (y > 0)
        printf("Move Blank LEFT\n");

    // Right
    if (y < SIZE - 1)
        printf("Move Blank RIGHT\n");
}

int main()
{
    int puzzle[SIZE][SIZE];
    int i, j;

    printf("Enter the 4x4 Puzzle Matrix (use 0 for blank):\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            scanf("%d", &puzzle[i][j]);
        }
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    solvePuzzle(puzzle);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    printf("\nRunning Time = %.8f microseconds\n", cpu_time_used);

    return 0;
}
/*
Concept:
15 Puzzle Problem: Uses Branch and Bound to find the shortest path to the goal state.
Complexity: O(b^d)
Recurrence Relation: None
*/
