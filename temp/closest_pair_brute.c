#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Point { int x, y; };

float dist(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(struct Point P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min) min = dist(P[i], P[j]);
    return min;
}

int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    struct Point *P = (struct Point *)malloc(n * sizeof(struct Point));
    printf("Enter coordinates (x y):\n");
    for (int i = 0; i < n; i++) scanf("%d %d", &P[i].x, &P[i].y);

    clock_t start = clock();
    float d = bruteForce(P, n);
    clock_t end = clock();

    printf("The smallest distance (Brute Force) is %f\n", d);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(P);
    return 0;
}

/*
Concept:
The Brute Force method for Closest Pair calculates the distance between 
every pair of points and returns the minimum distance.
Complexity: O(n^2)
Recurrence Relation: T(n) = O(n^2)
*/
