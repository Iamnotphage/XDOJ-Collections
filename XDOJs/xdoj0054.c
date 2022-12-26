//xdoj0054.c
#include<stdio.h>
int main(){
    int n,a,b,c;//1000-2000
    scanf("%d",&n);
    for(int i=1;i<1000;i++){//穷举1~1000的所有数,因为abc最多是三位数
        //abc最多三位数，分别求i的个十百位
        a=i%10;
        b=(i/10)%10;
        c=(i/100)%10;
        if(i+a*100+b*10+c==n){
            printf("%d %d %d\n",c,b,a);
        }
    }
    return 0;
}