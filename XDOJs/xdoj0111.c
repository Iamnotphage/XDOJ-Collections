//xdoj0111.c
#include<stdio.h>
int main(){
    unsigned int a;
    scanf("%d",&a);
    if(a%5==0&&a%7==0){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}