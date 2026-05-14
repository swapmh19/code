#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <ctime>

bool bfs(const std::vector<std::vector<int>>& rGraph, int s, int t, std::vector<int>& parent, int n) {
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(std::vector<std::vector<int>>& graph, int s, int t, int n) {
    std::vector<std::vector<int>> rGraph = graph;
    std::vector<int> parent(n);
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent, n)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (rGraph[u][v] < path_flow) path_flow = rGraph[u][v];
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n;
    std::cout << "Enter number of vertices: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::cout << "Enter capacity matrix:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> graph[i][j];

    int s, t;
    std::cout << "Enter source and sink vertex: ";
    std::cin >> s >> t;

    clock_t start = clock();
    int flow = fordFulkerson(graph, s, t, n);
    clock_t end = clock();

    std::cout << "Max Flow: " << flow << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Ford-Fulkerson Algorithm calculates the maximum flow in a flow network. 
It repeatedly finds augmenting paths using BFS (Edmonds-Karp variant) and 
increases the flow until no more paths can be found.
Complexity: O(V * E^2) with BFS.
Recurrence Relation: Flow(f) = Flow(f) + AugmentingPath(rGraph)
*/
