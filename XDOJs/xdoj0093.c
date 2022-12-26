//xdoj0093.c
#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",a>b?(a%10):(b%10),a>b?(b*b):(a*a));
    return 0;
}