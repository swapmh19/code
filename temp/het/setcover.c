#include <stdio.h>
#include <time.h>

void setCover(int set[][10], int n, int m)
{
    int covered[10] = {0};
    int selected[10] = {0};
    int coveredCount = 0;

    while (coveredCount < m)
    {
        int bestSet = -1;
        int maxCover = -1;

        // Find set covering maximum uncovered elements
        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 0)
            {
                int count = 0;

                for (int j = 0; j < m; j++)
                {
                    if (set[i][j] == 1 && covered[j] == 0)
                    {
                        count++;
                    }
                }

                if (count > maxCover)
                {
                    maxCover = count;
                    bestSet = i;
                }
            }
        }

        if (bestSet == -1)
        {
            break;
        }

        selected[bestSet] = 1;

        printf("Selected Set S%d : { ", bestSet + 1);

        for (int j = 0; j < m; j++)
        {
            if (set[bestSet][j] == 1)
            {
                printf("%d ", j + 1);

                if (covered[j] == 0)
                {
                    covered[j] = 1;
                    coveredCount++;
                }
            }
        }

        printf("}\n");
    }

    printf("\nFinal Selected Sets: ");
    for (int i = 0; i < n; i++)
    {
        if (selected[i] == 1)
        {
            printf("S%d ", i + 1);
        }
    }

    printf("\n");
}

int main()
{
    int n, m;
    int set[10][10];

    printf("Enter number of sets: ");
    scanf("%d", &n);

    printf("Enter number of elements in universal set: ");
    scanf("%d", &m);

    printf("\nEnter set matrix (1 if element present else 0):\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &set[i][j]);
        }
    }

    clock_t start, end;

    start = clock();

    setCover(set, n, m);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution Time = %.8f seconds\n", time_taken);

    return 0;
}
/*
Concept:
Set Cover (Greedy): Finds an approximate solution to the set cover problem.
Complexity: Polynomial approx
Recurrence Relation: None
*/
