//xdoj0066.c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    double sum=0;
    int num[100];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++){
        sum+=num[i];
    }
    printf("%.2lf",sum/n);
    return 0;
}