//xdoj0112.c
#include<stdio.h>
#include<math.h>
int main(){
    double x;
    scanf("%lf",&x);
    printf("%.2f",x>=0?sqrt(x):(pow(x+1,2)+2*x+1/x));
    return 0;
}