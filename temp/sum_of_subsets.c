#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void subsetSum(int set[], int subset[], int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        printf("Subset found: ");
        for (int i = 0; i < subSize; i++) printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    for (int i = nodeCount; i < n; i++) {
        subset[subSize] = set[i];
        subsetSum(set, subset, n, subSize + 1, total + set[i], i + 1, sum);
    }
}

int main() {
    int n, sum;
    printf("Enter number of elements in set: ");
    scanf("%d", &n);
    int set[n], subset[n];
    printf("Enter elements of set: ");
    for (int i = 0; i < n; i++) scanf("%d", &set[i]);
    printf("Enter target sum: ");
    scanf("%d", &sum);

    clock_t start = clock();
    subsetSum(set, subset, n, 0, 0, 0, sum);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Sum of Subsets problem finds all subsets of a given set whose elements 
sum up to a target value. It uses Backtracking to explore the state 
space tree and prunes branches that cannot lead to a solution.
Complexity: O(2^n)
Recurrence Relation: T(n) = 2T(n-1) + O(1)
*/
