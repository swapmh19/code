#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <ctime>

struct Point { int x, y; };

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(const std::vector<Point>& P, int offset, int n) {
    float min_dist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            float d = dist(P[offset + i], P[offset + j]);
            if (d < min_dist) min_dist = d;
        }
    return min_dist;
}

float stripClosest(std::vector<Point>& strip, float d) {
    float min_dist = d;
    std::sort(strip.begin(), strip.end(), compareY);
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; ++j) {
            float distance = dist(strip[i], strip[j]);
            if (distance < min_dist) min_dist = distance;
        }
    return min_dist;
}

float closestRecursive(std::vector<Point>& P, int offset, int n) {
    if (n <= 3) return bruteForce(P, offset, n);
    int mid = n / 2;
    Point midPoint = P[offset + mid];
    float dl = closestRecursive(P, offset, mid);
    float dr = closestRecursive(P, offset + mid, n - mid);
    float d = std::min(dl, dr);
    
    std::vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (std::abs(P[offset + i].x - midPoint.x) < d) 
            strip.push_back(P[offset + i]);
            
    return std::min(d, stripClosest(strip, d));
}

int main() {
    int n;
    std::cout << "Enter number of points: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<Point> P(n);
    std::cout << "Enter coordinates (x y):" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> P[i].x >> P[i].y;

    std::sort(P.begin(), P.end(), compareX);
    
    clock_t start = clock();
    float d = closestRecursive(P, 0, n);
    clock_t end = clock();

    std::cout << "The smallest distance (Divide & Conquer) is " << d << std::endl;
    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    
    return 0;
}

/*
Concept:
The Closest Pair problem finds the two closest points in a set.
Using Divide and Conquer:
1. Sort points by X-coordinate.
2. Split points into two halves.
3. Find min distance in left and right halves.
4. Find min distance among points near the dividing line (strip).
Complexity: O(n log n)
Recurrence Relation: T(n) = 2T(n/2) + O(n log n)
*/
