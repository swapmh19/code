#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int n;
std::vector<std::vector<int>> dist;
int min_path = INT_MAX;

void tspBacktrack(int curr_pos, int count, int cost, std::vector<bool>& visited) {
    if (count == n && dist[curr_pos][0] > 0) {
        if (cost + dist[curr_pos][0] < min_path)
            min_path = cost + dist[curr_pos][0];
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[curr_pos][i] > 0) {
            visited[i] = true;
            tspBacktrack(i, count + 1, cost + dist[curr_pos][i], visited);
            visited[i] = false;
        }
    }
}

int main() {
    std::cout << "Enter number of cities: ";
    if (!(std::cin >> n)) return 0;
    
    dist.assign(n, std::vector<int>(n));
    std::cout << "Enter distance matrix:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> dist[i][j];

    std::vector<bool> visited(n, false);
    visited[0] = true;

    clock_t start = clock();
    tspBacktrack(0, 1, 0, visited);
    clock_t end = clock();

    std::cout << "Min distance (Backtracking): " << min_path << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Backtracking method for TSP explores all possible permutations of 
cities to find the shortest Hamiltonian cycle. It visits each city 
one by one and backtracks when all paths from a city are explored.
Complexity: O(n!)
Recurrence Relation: T(n) = n * T(n-1) + O(n)
*/
