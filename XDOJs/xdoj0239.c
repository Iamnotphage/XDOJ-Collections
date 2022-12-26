//xdoj0239.c
#include<stdio.h>
int Cnm(int n,int m){//组合数
    if(m==0||m==n){
        return 1;
    }
    int n1=n;
    int m1=m;
    for(int i=n-m+1;i<n;i++){
        n1*=i;
    }
    for(int i=1;i<m;i++){
        m1*=i;
    }
    return n1/m1;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n>=2&&n<=10){
        printf("1\n");//第一行
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                printf("%d ",Cnm(i,j));
            }
            printf("\n");
        }
    }
    return 0;
}