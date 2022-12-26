//xdoj0149.c
#include<stdio.h>
int main(){
    int n,flag=1;
    double sum=0;
    scanf("%d",&n);
    for(double i=1;i<=n;i++){
        sum=sum+flag*(i/(2*i-1));
        flag*=-1;
    }
    printf("%.3f",sum);
    return 0;
}