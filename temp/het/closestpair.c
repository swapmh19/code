#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Point
{
    int x, y;
};

int compareX(const void *a, const void *b)
{
    return ((struct Point *)a)->x - ((struct Point *)b)->x;
}
int compareY(const void *a, const void *b)
{
    return ((struct Point *)a)->y - ((struct Point *)b)->y;
}

float dist(struct Point p1, struct Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float min(float x, float y) { return (x < y) ? x : y; }

float bruteForce(struct Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float stripClosest(struct Point strip[], int size, float d)
{
    float min = d;
    qsort(strip, size, sizeof(struct Point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}

float closestRecursive(struct Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);
    int mid = n / 2;
    struct Point midPoint = P[mid];
    float dl = closestRecursive(P, mid);
    float dr = closestRecursive(P + mid, n - mid);
    float d = min(dl, dr);
    struct Point *strip = (struct Point *)malloc(n * sizeof(struct Point));
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];
    float result = min(d, stripClosest(strip, j, d));
    free(strip);
    return result;
}

int main()
{
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    struct Point *P = (struct Point *)malloc(n * sizeof(struct Point));
    printf("Enter coordinates (x y):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &P[i].x, &P[i].y);

    qsort(P, n, sizeof(struct Point), compareX);
    clock_t start = clock();
    float d = closestRecursive(P, n);
    clock_t end = clock();

    printf("The smallest distance (Divide & Conquer) is %f\n", d);
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(P);
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