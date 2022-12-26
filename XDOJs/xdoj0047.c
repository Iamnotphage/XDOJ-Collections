//xdoj0047.c
#include<stdio.h>
int main(){
    int h,m;
    scanf("%d",&h);
    scanf("%d",&m);
    printf("%.2f",-20+4*(h+(double)m/60)*(h+(double)m/60)/((h+(double)m/60)+2));
    return 0;
}