#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

struct Item { int value, weight; };

bool compare(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Item>& items, int n) {
    std::sort(items.begin(), items.end(), compare);
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
    std::cout << "Enter number of items: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<Item> items(n);
    std::cout << "Enter value and weight of items:" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> items[i].value >> items[i].weight;
    
    std::cout << "Enter capacity: ";
    std::cin >> W;

    clock_t start = clock();
    double res = fractionalKnapsack(W, items, n);
    clock_t end = clock();

    std::cout << "Max value: " << res << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

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
