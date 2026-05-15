#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SETS 10
#define MAX_ELEMENTS 10

int main() {
    int n, m;
    printf("Enter number of elements in universe: ");
    scanf("%d", &n);
    printf("Enter number of sets: ");
    scanf("%d", &m);

    bool sets[MAX_SETS][MAX_ELEMENTS] = {0};
    for (int i = 0; i < m; i++) {
        int count;
        printf("Enter number of elements in set %d: ", i);
        scanf("%d", &count);
        printf("Enter elements: ");
        for (int j = 0; j < count; j++) {
            int val;
            scanf("%d", &val);
            sets[i][val] = true;
        }
    }

    bool covered[MAX_ELEMENTS] = {0};
    int coveredCount = 0;
    bool chosenSets[MAX_SETS] = {0};

    clock_t start = clock();
    while (coveredCount < n) {
        int bestSet = -1;
        int maxNew = 0;
        for (int i = 0; i < m; i++) {
            if (!chosenSets[i]) {
                int newElements = 0;
                for (int j = 0; j < n; j++)
                    if (sets[i][j] && !covered[j]) newElements++;
                if (newElements > maxNew) {
                    maxNew = newElements;
                    bestSet = i;
                }
            }
        }
        if (bestSet == -1) break;
        chosenSets[bestSet] = true;
        for (int j = 0; j < n; j++) {
            if (sets[bestSet][j] && !covered[j]) {
                covered[j] = true;
                coveredCount++;
            }
        }
    }
    clock_t end = clock();

    printf("Chosen sets: ");
    for (int i = 0; i < m; i++) if (chosenSets[i]) printf("%d ", i);
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Set Cover Problem is NP-hard. The Greedy Approximation Algorithm 
repeatedly picks the set that covers the maximum number of remaining 
uncovered elements. It provides a log(n) approximation.
Complexity: O(m * n)
Recurrence Relation: T(n) = O(m * n)
*/
