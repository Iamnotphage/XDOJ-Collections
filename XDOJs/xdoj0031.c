//xdoj0031.c
#include<stdio.h>
//int gcd(int a,int b){
//    return(b?gcd(b,a%b):a);
//}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int r;
    while(a%b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    printf("%d",b);
    return 0;
}