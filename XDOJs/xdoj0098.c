//xdoj0098.c
#include<stdio.h>
int main(){
    double m;
    scanf("%lf",&m);
    if(m>=90){
        printf("%.2f %c",m,65);
    }else if(m>=80&&m<=89){
        printf("%.2f %c",m,66);
    }else if(m>=70&&m<=79){
        printf("%.2f %c",m,67);
    }else if(m>=60&&m<=69){
        printf("%.2f %c",m,68);
    }else{
        printf("%.2f %c",m,69);
    }
    return 0;
}