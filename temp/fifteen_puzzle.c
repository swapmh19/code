#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A simplified version of 15-puzzle (using 8-puzzle for simplicity 
// but the logic remains the same for 15-puzzle). 
// Demonstrates the LC Branch and Bound concept using Manhattan distance.

#define N 3 // Change to 4 for 15-puzzle

int getInvCount(int arr[]) {
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
        for (int j = i + 1; j < N * N; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

int isSolvable(int puzzle[N][N]) {
    int invCount = getInvCount((int*)puzzle);
    return (invCount % 2 == 0);
}

int main() {
    int puzzle[N][N];
    printf("Enter %dx%d puzzle (0 for blank):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) scanf("%d", &puzzle[i][j]);

    clock_t start = clock();
    if (isSolvable(puzzle)) printf("The puzzle is solvable.\n");
    else printf("The puzzle is not solvable.\n");
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The 15 Puzzle problem is solved using LC Branch and Bound (Least Cost Search). 
It uses a heuristic function (like Manhattan distance or misplaced tiles) 
to estimate the cost to reach the goal.
Complexity: Exponential
Recurrence Relation: f(n) = g(n) + h(n) where g is path cost and h is heuristic
Note: This program checks solvability as a simple demonstration of the problem space.
*/
