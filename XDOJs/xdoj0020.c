//xdoj0020.c
#include<stdio.h>
int main(){
    int a,b;
    char c;
    scanf("%d",&a);
    scanf("%c",&c);
    scanf("%d",&b);
    if(c=='%'){
        printf("%d%c%d=%d",a,c,b,a%b);
    }else if(c=='+'){
        printf("%d%c%d=%d",a,c,b,a+b);
    }else if(c=='-'){
        printf("%d%c%d=%d",a,c,b,a-b);
    }else if(c=='*'){
        printf("%d%c%d=%d",a,c,b,a*b);
    }else if(c=='/'&&b!=0){
        printf("%d%c%d=%d",a,c,b,a/b);
    }
    return 0;
}