#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <ctime>

struct Point { int x, y; };

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(const std::vector<Point>& P, int n) {
    float min_dist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            float d = dist(P[i], P[j]);
            if (d < min_dist) min_dist = d;
        }
    return min_dist;
}

int main() {
    int n;
    std::cout << "Enter number of points: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<Point> P(n);
    std::cout << "Enter coordinates (x y):" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> P[i].x >> P[i].y;

    clock_t start = clock();
    float d = bruteForce(P, n);
    clock_t end = clock();

    std::cout << "The smallest distance (Brute Force) is " << d << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    
    return 0;
}

/*
Concept:
The Brute Force method for Closest Pair calculates the distance between 
every pair of points and returns the minimum distance.
Complexity: O(n^2)
Recurrence Relation: T(n) = O(n^2)
*/
