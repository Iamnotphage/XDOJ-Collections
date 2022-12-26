//xdoj0053.c
#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    if(m>=90){
        putchar(65);
    }else if(m>=80&&m<=89){
        putchar(66);
    }else if(m>=70&&m<=79){
        putchar(67);
    }else if(m>=60&&m<=69){
        putchar(68);
    }else{
        putchar(69);
    }
    return 0;
}