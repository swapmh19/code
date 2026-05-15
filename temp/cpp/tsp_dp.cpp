#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int n_cities;
std::vector<std::vector<int>> dist_matrix;
int visited_all_mask;
std::vector<std::vector<int>> memo;

int tsp(int mask, int pos) {
    if (mask == visited_all_mask) return dist_matrix[pos][0];
    if (memo[mask][pos] != -1) return memo[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n_cities; city++) {
        if ((mask & (1 << city)) == 0) {
            int subAns = tsp(mask | (1 << city), city);
            if (subAns != INT_MAX) {
                int newAns = dist_matrix[pos][city] + subAns;
                if (newAns < ans) ans = newAns;
            }
        }
    }
    return memo[mask][pos] = ans;
}

int main() {
    std::cout << "Enter number of cities: ";
    if (!(std::cin >> n_cities)) return 0;
    
    dist_matrix.assign(n_cities, std::vector<int>(n_cities));
    std::cout << "Enter distance matrix:" << std::endl;
    for (int i = 0; i < n_cities; i++)
        for (int j = 0; j < n_cities; j++) std::cin >> dist_matrix[i][j];

    visited_all_mask = (1 << n_cities) - 1;
    memo.assign(1 << n_cities, std::vector<int>(n_cities, -1));

    clock_t start = clock();
    int min_dist = tsp(1, 0);
    clock_t end = clock();

    std::cout << "Min distance: " << min_dist << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Travelling Salesman Problem (TSP) finds the shortest possible route 
that visits each city exactly once and returns to the origin. 
This implementation uses Dynamic Programming with Bitmasking.
Complexity: O(n^2 * 2^n)
Recurrence Relation: cost(mask, pos) = min_{city} {dist[pos][city] + cost(mask | (1 << city), city)}
*/
