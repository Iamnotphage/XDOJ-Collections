//xdoj0009.c
//已知铁的比重是7.86(克/立方厘米)，金的比重是19.3(克/立方厘米)。写一个程序，分别计算出给定直径的铁球与金球的质量，假定PI=3.1415926
#include<stdio.h>
int main(){
    const double pi=3.1415926;
    const double iron=0.00786;
    const double gold=0.0193;
    int d1,d2;
    scanf("%d",&d1);
    scanf("%d",&d2);
    printf("%.3f %.3f",4*pi*d1*d1*d1*iron/24,4*pi*d2*d2*d2*gold/24);
    return 0;
}