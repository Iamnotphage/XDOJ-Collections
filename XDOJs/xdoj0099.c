//xdoj0099.c
#include<stdio.h>
int main(){
    int es[3]={0,110,210};
    double e;
    scanf("%lf",&e);
    if(e>=es[0]&&e<=es[1]){
        //每度0.5元
        printf("%.2lf %c %.2f",e/2,65,0.00);
    }else if(e>es[1]&&e<=es[2]){
        //超过部分0.55元
        printf("%.2lf %c %.2f",55+(e-110)*0.55,66,e-110);
    }else{
        //每度电0.70元
        printf("%.2lf %c %.2f",110+0.7*(e-210),67,e-210);
    }
    return 0;
}