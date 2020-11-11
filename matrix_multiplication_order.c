#include<stdio.h>
#include<limits.h>
int a[100][100],kval[100][100],p[100],n,m,min=INT_MAX;
void printorder(int i,int j) {
    if(i==j)
        printf("A%d",i);
    else if(i<j) {
        printf("(");
        printorder(i,kval[i][j]);
        printorder(kval[i][j]+1,j);
        printf(")");
    }
}
int main() {
    printf("Enter no. of matrices\n");
    scanf("%d",&n);
    printf("Enter the orders of matrices\n");
    for(int i=0;i<=n;i++) scanf("%d",&p[i]);
    for(int j=1;j<n;j++) {
        for(int i=1;i<=n-j;i++) {
            for(int k=i;k<i+j;k++) {
                m=a[i][k]+a[k+1][i+j]+p[i-1]*p[k]*p[i+j];
                if(min>m) {
                    min=m;
                    kval[i][i+j]=k;
                }
            }
            a[i][i+j]=min;
            min=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            printf("%d ",kval[i][j]);
        printf("\n");
    }
    printf("\n");
    printorder(1,n);
}
