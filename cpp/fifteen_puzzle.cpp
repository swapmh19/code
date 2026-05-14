#include <iostream>
#include <vector>
#include <ctime>

#define N 3 

int getInvCount(const std::vector<int>& arr) {
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
        for (int j = i + 1; j < N * N; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

bool isSolvable(const std::vector<std::vector<int>>& puzzle) {
    std::vector<int> arr;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            arr.push_back(puzzle[i][j]);
    int invCount = getInvCount(arr);
    return (invCount % 2 == 0);
}

int main() {
    std::vector<std::vector<int>> puzzle(N, std::vector<int>(N));
    std::cout << "Enter " << N << "x" << N << " puzzle (0 for blank):" << std::endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) std::cin >> puzzle[i][j];

    clock_t start = clock();
    if (isSolvable(puzzle)) std::cout << "The puzzle is solvable." << std::endl;
    else std::cout << "The puzzle is not solvable." << std::endl;
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
