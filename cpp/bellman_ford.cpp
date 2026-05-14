#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

struct Edge { int src, dest, weight; };

void bellmanFord(int V, int E, const std::vector<Edge>& edges, int src) {
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < V; i++) 
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

int main() {
    int V, E;
    std::cout << "Enter number of vertices and edges: ";
    if (!(std::cin >> V >> E)) return 0;
    
    std::vector<Edge> edges(E);
    std::cout << "Enter edges (src dest weight):" << std::endl;
    for (int i = 0; i < E; i++)
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    int src;
    std::cout << "Enter source vertex: ";
    std::cin >> src;

    clock_t start = clock();
    bellmanFord(V, E, edges, src);
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Bellman-Ford Algorithm finds the shortest path from a source to all other 
vertices in a weighted graph. Unlike Dijkstra, it can handle negative 
edge weights and detect negative weight cycles.
Complexity: O(V*E)
Recurrence Relation: T(i, v) = min(T(i-1, v), min_{u} {T(i-1, u) + w(u, v)})
*/
