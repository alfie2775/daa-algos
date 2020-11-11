#include<stdio.h>
int u,v,n,near[100],mincost=1000,a[100][100],tree[100][3];
int findmin() {
    int k,min=1000;
    for(int j=1;j<=n;j++)
        if(near[j]!=0&&min>a[j][near[j]]) {
            min=a[j][near[j]];
            k=j;
        }
    return k;
}
int main() {
    printf("Enter no. of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
            if(mincost>a[i][j]) {
                mincost=a[i][j];
                u=i; v=j;
            }
        }
    for(int i=1;i<=n;i++)
        if(a[i][u]<=a[i][v])
            near[i]=u;
        else
            near[i]=v;
    near[u]=near[v]=0;
    tree[1][1]=u; tree[1][2]=v;
    for(int i=2;i<n;i++) {
        int j=findmin();
        mincost+=a[j][near[j]];
        tree[i][1]=j; tree[i][2]=near[j];
        near[j]=0;
        for(int k=1;k<=n;k++)
            if(near[k]!=0&&a[k][j]<a[k][near[k]])
                near[k]=j;
    }
    printf("Minimum cost of the spanning tree is %d\n",mincost);
    printf("Edges and its weights in spanning tree\n");
    for(int i=1;i<n;i++) {
        printf("Edge: %d--%d Weight: %d\n",tree[i][1],tree[i][2],a[tree[i][1]][tree[i][2]]);
    }
}
