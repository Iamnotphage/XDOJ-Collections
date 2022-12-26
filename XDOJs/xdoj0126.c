//xdoj0126.c
#include<stdio.h>
#include<math.h>
int main(){
    double d,p,r,m;
    scanf("%lf%lf%lf",&d,&p,&r);
    m=(log10(p)-log10(p-d*r))/log10(1+r);
    printf("%.2f",m);
    return 0;
}