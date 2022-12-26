//xdoj0247.c
//xdoj0068.c
#include<stdio.h>
int main(){
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int y,d,t,sum=0,i=0;
    scanf("%d%d",&y,&d);
    if(y%400==0||(y%100!=0&&y%4==0)){
        months[1] =29;
    }
    for(;i<12;i++){
        sum+=months[i];
        if(sum>=d){//d-(sum-months[i])先sum减去该索引的天数，得到前几个月天数之和，再用d减去就行
            printf("%d %d",i+1,d-sum+months[i]);
            break;
        }
    }
    return 0;
}