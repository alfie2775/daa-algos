#include <stdio.h>
int n, f[100], s[100];
char c[100];
typedef struct n2
{
    char data;
    int freq;
    struct n2 *l;
    struct n2 *r;
} n2;
typedef struct n1
{
    struct n2 *link;
    struct n1 *next;
} n1;
n1 *start = NULL;
void insert()
{
    n1 *nn = (n1 *)malloc(sizeof(n1));
    if (start == NULL)
    {
        start = nn;
        nn->next = NULL;
    }
    else
    {
        nn->next = start;
        start = nn;
    }
}
void createList()
{
    for (int i = 0; i < n; i++)
        insert();
    n1 *temp = start;
    for (int i = 0; i < n; i++)
    {
        n2 *nn = (n2 *)malloc(sizeof(n2));
        nn->data = c[i];
        nn->freq = f[i];
        nn->l = nn->r = NULL;
        temp->link = nn;
        temp = temp->next;
    }
}
void sortList()
{
    for (int i = 0; i < n; i++)
    {
        n1 *t1 = start, *t2 = start->next;
        n2 *t;
        while (t2 != NULL)
        {
            if (t1->link->freq > t2->link->freq)
            {
                t = t1->link;
                t1->link = t2->link;
                t2->link = t;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
}
void printcodes(n2 *n, int i)
{
    if (n != NULL)
    {
        s[i] = 0;
        printcodes(n->l, i + 1);
        if (isalpha(n->data))
        {
            printf("Code of %c is ", n->data);
            for (int j = 0; j < i; j++)
                printf("%d", s[j]);
            printf("\n");
        }
        s[i] = 1;
        printcodes(n->r, i + 1);
    }
}
int main()
{
    printf("Enter no. of elements\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &c[i]);
        scanf("%d", &f[i]);
    }
    createList();
    while (start->next != NULL)
    {
        sortList();
        n2 *nn = (n2 *)malloc(sizeof(n2));
        nn->freq = start->link->freq + start->next->link->freq;
        nn->data = '-';
        nn->l = start->link;
        nn->r = start->next->link;
        start->next->link = nn;
        start = start->next;
    }
    printcodes(start->link, 0);
}
