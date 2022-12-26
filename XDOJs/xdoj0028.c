//xdoj0028.c
#include<stdio.h>
int main(){
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a,b;
    scanf("%d%d",&a,&b);
    if(a%4==0&&a%100!=0||a%400==0){//闰年的二月
        if(b==2){
            printf("%d",days[b-1]+1);
        }
    }else{
        printf("%d",days[b-1]);
    }

    return 0;
}