//xdoj002.c
//温度转换
#include<stdio.h>
int main(){
    int h;
    scanf("%d",&h);
    printf("%.2f",((double)h-32)*5/9);
    return 0;
}