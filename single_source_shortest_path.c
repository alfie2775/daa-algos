#include<stdio.h>
int n,d[100],v,a[100][100],mini,min,not[100];
int minvertex() {
    int u;
    min=1000;
    for(int i=1;i<=n;i++)
        if(not[i]==0)
            if(min>d[i]) {
                min=d[i];
                u=i;
            }
    not[u]++;
    return u;
}
void ans(int l[]) {
    for(int i=1;i<=n;i++)
        if(l[i]==1000)
            printf("%d--%d : INF\n",v,i);
        else
            printf("%d--%d : %d\n",v,i,l[i]);
}
int main() {
    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=1000;
        }
    printf("Enter starting vertex\n");
    scanf("%d",&v);
    not[v]++;
    for(int i=1;i<=n;i++)
        d[i]=a[v][i];
    for(int i=2;i<n;i++) {
        mini=minvertex();
        for(int j=1;j<=n;j++){
            if(d[j]>min+a[mini][j])
                d[j]=min+a[mini][j];
            d[v]=1000;
        }
    }
    ans(d);
    /*
    OP TEST CASE:
    0 50 45 10 0 0
0 0 10 0 0 0
0 0 0 0 20 0
10 0 0 0 15 0
0 20 35 0 0 0
0 0 0 0 3 0*/
}
