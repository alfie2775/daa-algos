#include<stdio.h>
#define inf 1000
int n,a[100][100],ans[100][100];
int min(int a,int b) {
    return a<b?a:b;
}
int main() {
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
    printf("Shortest path matrix\n");
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) if(a[i][j]==inf) printf("INF "); else printf("%3d ",a[i][j]);
        printf("\n");
    }
}
