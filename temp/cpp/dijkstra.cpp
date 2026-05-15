#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet, int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(const std::vector<std::vector<int>>& graph, int src, int n) {
    std::vector<int> dist(n, INT_MAX);
    std::vector<bool> sptSet(n, false);
    
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        if (u == -1) break;
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < n; i++) 
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

int main() {
    int n;
    std::cout << "Enter number of vertices: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::cout << "Enter adjacency matrix (0 for no edge):" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> graph[i][j];

    int src;
    std::cout << "Enter source vertex: ";
    std::cin >> src;

    clock_t start = clock();
    dijkstra(graph, src, n);
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Dijkstra's Algorithm finds the shortest path from a source vertex to all 
other vertices in a weighted graph with non-negative edge weights. 
It uses a greedy approach by always picking the nearest unvisited vertex.
Complexity: O(V^2) for adjacency matrix.
Recurrence Relation: T(V) = T(V-1) + O(V)
*/
