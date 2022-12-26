//xdoj0163.c
#include<stdio.h>
const int N=20;
int main(){
    int a[N][N];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i][i]+a[i][n-i-1];
    }
    if(n%2==0){
        printf("%d",sum);
    }else{
        printf("%d",sum-a[n/2][n/2]);
    }
    return 0;
}