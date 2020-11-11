#include <stdio.h>
#include <stdlib.h>
int n, x[100];
int isPossibleToPlace(int i, int j)
{
    for (int k = 1; k < i; k++)
        if (x[k] == j || abs(x[k] - j) == abs(i - k))
            return 0;
    return 1;
}
void printSolution()
{
    static int k = 1;
    printf("Solution %d:\n[", k++);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", x[i]);
        if (i < n)
            printf(",");
    }
    printf("]\n");
}
void nQueen(int i)
{
    for (int k = 1; k <= n; k++)
        if (isPossibleToPlace(i, k))
        {
            x[i] = k;
            if (i == n)
                printSolution();
            else
                nQueen(i + 1);
        }
}
int main()
{
    printf("Enter no. of rows\n");
    scanf("%d", &n);
    nQueen(1);
}
