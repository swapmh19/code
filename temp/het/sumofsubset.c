#include <stdio.h>
#include <time.h>

void subsetSum(int set[], int n, int sum)
{
    int i, j;
    int totalSubsets = 1 << n; // 2^n subsets
    int found = 0;

    printf("Subsets with sum %d are:\n", sum);

    // Generate all subsets using backtracking idea
    for (i = 0; i < totalSubsets; i++)
    {
        int currentSum = 0;

        // Calculate sum of current subset
        for (j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                currentSum += set[j];
            }
        }

        // If subset sum matches target
        if (currentSum == sum)
        {
            found = 1;
            printf("{ ");

            for (j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    printf("%d ", set[j]);
                }
            }

            printf("}\n");
        }
    }

    if (!found)
    {
        printf("No subset found.\n");
    }
}

int main()
{
    int n, i, sum;
    int set[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &sum);

    clock_t start, end;

    start = clock();

    subsetSum(set, n, sum);

    end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    printf("\nExecution Time: %.8f microseconds\n", time_taken);

    return 0;
}
/*
Concept:
Sum of Subsets: Uses Backtracking to find subsets that sum to a given value.
Complexity: O(2^n)
Recurrence Relation: None
*/
