#include <iostream>
#include <vector>
#include <ctime>

#define M 100 // Applicants
#define N 100 // Jobs

bool bpm(const std::vector<std::vector<bool>>& bpGraph, int u, std::vector<bool>& visited, std::vector<int>& matchR, int n) {
    for (int v = 0; v < n; v++) {
        if (bpGraph[u][v] && !visited[v]) {
            visited[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], visited, matchR, n)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(const std::vector<std::vector<bool>>& bpGraph, int m, int n) {
    std::vector<int> matchR(n, -1);
    int result = 0;
    for (int u = 0; u < m; u++) {
        std::vector<bool> visited(n, false);
        if (bpm(bpGraph, u, visited, matchR, n)) result++;
    }
    return result;
}

int main() {
    int m, n;
    std::cout << "Enter number of applicants and jobs: ";
    if (!(std::cin >> m >> n)) return 0;

    std::vector<std::vector<bool>> bpGraph(m, std::vector<bool>(n));
    std::cout << "Enter adjacency matrix (1 if applicant i can do job j):" << std::endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int val;
            std::cin >> val;
            bpGraph[i][j] = (val != 0);
        }

    clock_t start = clock();
    int res = maxBPM(bpGraph, m, n);
    clock_t end = clock();

    std::cout << "Maximum number of matching is " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
The Bipartite Matching Problem finds the maximum number of edges that 
do not share a common vertex in a bipartite graph. It can be solved 
by converting it to a Max Flow problem or using the augmenting path 
algorithm (as shown here).
Complexity: O(V*E)
Recurrence Relation: Matching(u) = (v is free or Matching(matchR[v]))
*/
