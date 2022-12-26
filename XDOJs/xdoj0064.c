//xdoj0064.c
#include<stdio.h>
int main(){
    //给奇数排序的话，n^3等于n个奇数合
    //可以证明最后一个奇数的序号就是n(n+1)/2
    //第一个奇数的序号就是(n-1)n/2
    //第一个奇数的值是n^2-n+1
    //最后一个奇数的值是序号的两倍减去一 也就是n^2+n-1
    int n;
    scanf("%d",&n);
    for(int i=(n*n-n+1);i<=(n*n+n-1);i+=2){
        printf("%d ",i);
    }
    return 0;
}