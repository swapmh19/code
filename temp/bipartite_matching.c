#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define M 100 // Applicants
#define N 100 // Jobs

bool bpm(bool bpGraph[M][N], int u, bool visited[], int matchR[], int n) {
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

int maxBPM(bool bpGraph[M][N], int m, int n) {
    int matchR[n];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < m; u++) {
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        if (bpm(bpGraph, u, visited, matchR, n)) result++;
    }
    return result;
}

int main() {
    int m, n;
    printf("Enter number of applicants and jobs: ");
    scanf("%d %d", &m, &n);
    bool bpGraph[M][N];
    printf("Enter adjacency matrix (1 if applicant i can do job j):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            bpGraph[i][j] = val;
        }

    clock_t start = clock();
    int res = maxBPM(bpGraph, m, n);
    clock_t end = clock();

    printf("Maximum number of matching is %d\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

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
