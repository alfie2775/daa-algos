#include<stdio.h>
int w[100],p[100],x[100],dp[100][100],m,n;
int max(int a,int b) {
    return a>b?a:b;
}
int main() {
    printf("Enter the no. of items and capacity of knapsack\n");
    scanf("%d %d",&n,&m);
    printf("Enter weight and profit of each item\n");
    for(int i=1;i<=n;i++) scanf("%d %d",&w[i],&p[i]);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
        }
    }
    printf("Maximum profit that can be obtained is %d\n",dp[n][m]);
    for(int i=n,j=m;i>=0;i--) {
        if(dp[i][j]!=dp[i-1][j]) {
            x[i]=1;
            j-=w[i];
        }
    }
    printf("Items included are [");
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
        if(i<n)
            printf(",");
    }
    printf("]");

}
