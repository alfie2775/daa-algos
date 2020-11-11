#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int ind;
    int val;
} node;
node a[100];
int n, m, x[100];
int cmp(const void *a, const void *b)
{
    return ((node *)a)->val - ((node *)b)->val;
}
void write()
{
    static int k = 1;
    printf("Solution %d: ", k);
    for (int i = 1; i <= n; i++)
        if (x[i])
            printf("%d ", i);
    printf("\n");
    k++;
}
void subsets(int s, int k, int r)
{
    x[a[k].ind] = 1;
    if (s + a[k].val == m)
        write();
    else if (s + a[k].val + a[k + 1].val <= m)
        subsets(s + a[k].val, k + 1, r - a[k].val);
    if (s + r >= m && s + a[k + 1].val <= m)
    {
        x[a[k].ind] = 0;
        subsets(s, k + 1, r - a[k].val);
    }
}
int main()
{
    int r = 0;
    printf("Enter the no. of elements and the sum of a subset\n");
    scanf("%d %d", &n, &m);
    printf("Enter the array\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        r += a[i].val;
        a[i].ind = i;
    }
    qsort(a + 1, n, sizeof(node), cmp);
    subsets(0, 1, r);
}
