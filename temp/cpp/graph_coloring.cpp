#include <iostream>
#include <vector>
#include <ctime>

bool isSafe(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& color, int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == color[i]) return false;
    return true;
}

bool graphColoringUtil(const std::vector<std::vector<int>>& graph, int m, std::vector<int>& color, int v, int n) {
    if (v == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, n)) return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m;
    std::cout << "Enter number of vertices: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::cout << "Enter adjacency matrix:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> graph[i][j];
    
    std::cout << "Enter number of colors: ";
    std::cin >> m;

    std::vector<int> color(n, 0);

    clock_t start = clock();
    if (graphColoringUtil(graph, m, color, 0, n)) {
        std::cout << "Colors assigned: ";
        for (int i = 0; i < n; i++) std::cout << color[i] << " ";
        std::cout << std::endl;
    } else std::cout << "Solution does not exist" << std::endl;
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    return 0;
}

/*
Concept:
The Graph Coloring Problem assigns colors to vertices such that no two 
adjacent vertices have the same color. It uses Backtracking to try 
different colors for each vertex and backtrack if no color is valid.
Complexity: O(m^V)
Recurrence Relation: T(n) = m * T(n-1) + O(n)
*/
