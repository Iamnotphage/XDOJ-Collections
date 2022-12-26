//xdoj0183.c
#include<stdio.h>
int GreatCommonDivsior(int a,int b){
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    //最小公倍数=两数的乘积 除 最大公约数
    printf("%d %d",GreatCommonDivsior(a,b),a*b/GreatCommonDivsior(a,b));
    return 0;
}