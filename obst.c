#include<stdio.h>
int n,min=9999,t,p[100],q[100],w[100][100],c[100][100],r[100][100];
void printtree(int i,int j) {

}
int main() {
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    printf("Enter p and q values\n");
    for(int i=1;i<=2*n+1;i++)
        if(i<=n)
            scanf("%d",&p[i]);
        else
            scanf("%d",&q[i-n-1]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i==j)
                w[i][i]=q[i];
            else if(i<j)
                w[i][j]=w[i][j-1]+p[j]+q[j];
    for(int j=1;j<=n;j++)
        for(int i=0;i<=n-j;i++) {
            for(int k=i+1;k<=i+j;k++) {
                t=c[i][k-1]+c[k][i+j]+w[i][i+j];
                if(min>t) {
                    min=t;
                    r[i][i+j]=k;
                }
            }
            c[i][i+j]=min;
            min=9999;
        }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++)
            printf("%d ",w[i][j]);
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++)
        printf("%d ",c[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++)
            printf("%d ",r[i][j]);
        printf("\n");
    }
    printf("\n");
}
