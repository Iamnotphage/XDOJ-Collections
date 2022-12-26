//xdoj0235.c
#include<stdio.h>
char *months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int main(){
    int n;
    scanf("%d",&n);
    if(n>1&&n<13){
        printf("%s",months[n-1]);
    }else{
        printf("wrong");
    }
    return 0;
}