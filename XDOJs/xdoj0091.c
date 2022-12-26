//xdoj0091.c
#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,s,p;
    scanf("%lf%lf%lf",&a,&b,&c);
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.2f",s);
    return 0;
}