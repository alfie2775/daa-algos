#include<stdio.h>
#include<string.h>
char x[100],y[100],z[100],a[100][100],d[100][100];
int m,n,max;
int maximum(int a,int b,int i,int j){
    d[i][j]=a>=b?0:1;
    return a>b?a:b;
}
int main() {
    printf("Enter the strings\n");
    scanf("%s %s",x,y);
    m=strlen(x);
    n=strlen(y);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(x[i-1]==y[j-1]) {
                d[i][j]=2;
                a[i][j]=a[i-1][j-1]+1;
            }
            else
                a[i][j]=maximum(a[i-1][j],a[i][j-1],i,j);
    int k=0;
    printf("Table and directions\n")
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            printf("(%d,%d) ",a[i][j],d[i][j]);
        printf("\n");
    }
    for(int i=m,j=n;i>=1&&j>=1;)
        if(d[i][j]==2){
            z[k++]=x[i-1];
            i--;
            j--;
        }
        else if(d[i][j]==0)
            i--;
        else
            j--;
    z[k]='\0';
    printf("Longest common subsequence of %s and %s is %s with length %d",x,y,strrev(z),k);
}
