//xdoj0185.c
#include<stdio.h>
#include<math.h>
int main(){
    double x1,x2,a,t;
    scanf("%lf",&a);
    x2=1;
    do{
        x1=x2;
        x2=0.5*(x1+a/x1);
    }while(fabs(x1-x2)>=1e-5);
    printf("%.5lf",x2);
    return 0;
}