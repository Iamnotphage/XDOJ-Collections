//xdoj0155.c
#include<stdio.h>
int main(){
    unsigned int n;
    int shit=1;
    int peach=0;
    scanf("%u",&n);
    printf("%d ",n);
    if(n>0&&n<=10){
        for(int i=1;i<=n;i++){
            shit*=i;
            peach+=shit;
        }
        printf("%d ",shit);
        printf("%d",peach);
    }else if(n==0){
        printf("%d %d",1,1);
    }
    
    return 0;
}