#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item { int value, weight; };

int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalvalue += items[i].value;
        } else {
            int remain = W - curWeight;
            finalvalue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter value and weight of items:\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &items[i].value, &items[i].weight);
    printf("Enter capacity: ");
    scanf("%d", &W);

    clock_t start = clock();
    double res = fractionalKnapsack(W, items, n);
    clock_t end = clock();

    printf("Max value: %f\n", res);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Concept:
The Fractional Knapsack Problem uses a Greedy approach. We calculate the 
value-to-weight ratio for each item, sort them by this ratio, and take 
as much as possible of the highest-ratio items first.
Complexity: O(n log n)
Recurrence Relation: T(n) = O(n log n)
*/
