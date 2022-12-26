//xdoj0032.c
#include<stdio.h>
int main(){
    int n;
    int count=0;
    scanf("%d",&n);
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else{
            n=3*n+1;
        }
        count++;
    }
    printf("%d",count);
    return 0;
}