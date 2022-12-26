//xdoj0147.c
#include<stdio.h>
int main(){
    int a,b;
    int sum=0;
    scanf("%d ",&a);
    while(a!=0){
        if(a%2!=0){
            sum=sum+a;
        }
        scanf("%d ",&a);
    }
    printf("%d",sum);
    return 0;
}