#include<stdio.h>
int n,a[100][100],x[100],nosol=1;
void nextval(int k) {
    while(1) {
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
            break;
        if(a[x[k-1]][x[k]]) {
            int j;
            for(j=1;j<k;j++)
                if(x[j]==x[k])
                    break;
            if(j==k)
                if(k<n||(k==n&&a[x[n]][x[1]]))
                    break;
        }
    }
}
void write() {
    nosol=0;
    for(int i=1;i<=n;i++){
        printf("%d",x[i]);
        if(i<n)
            printf("->");
    }
    printf("\n");
}
void hamiltonian(int k) {
    nextval(k);
    if(x[k]!=0)
        if(k==n)
            write();
        else
            hamiltonian(k+1);
}
int main() {
    printf("Enter no. of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    printf("Enter the starting vertex\n");
    scanf("%d",x+1);
    hamiltonian(2);
    if(nosol)
        printf("No hamiltonian cycle exists.");
}
