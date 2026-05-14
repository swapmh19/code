#include <iostream>
#include <vector>
#include <ctime>

#define MAX_SETS 10
#define MAX_ELEMENTS 10

int main() {
    int n, m;
    std::cout << "Enter number of elements in universe: ";
    if (!(std::cin >> n)) return 0;
    std::cout << "Enter number of sets: ";
    std::cin >> m;

    std::vector<std::vector<bool>> sets(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int count;
        std::cout << "Enter number of elements in set " << i << ": ";
        std::cin >> count;
        std::cout << "Enter elements: ";
        for (int j = 0; j < count; j++) {
            int val;
            std::cin >> val;
            if (val < n) sets[i][val] = true;
        }
    }

    std::vector<bool> covered(n, false);
    int coveredCount = 0;
    std::vector<bool> chosenSets(m, false);

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

    std::cout << "Chosen sets: ";
    for (int i = 0; i < m; i++) if (chosenSets[i]) std::cout << i << " ";
    std::cout << "\nTime taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
