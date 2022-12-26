//xdoj0249.c
#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int t=n;
    for(i=2;i<=t/2;i++){//因数不超一半,1肯定是因数，直接跳过,从2始 从小到大找
    //不用i<=n/2的原因是下面的操作会改变n的值
        while(n%i==0){
            printf("%d",i);
            n/=i;//直接除以因数i
            if(n!=1){
                printf("*");//不是1表示 仍有因数，输出乘号
            }
        }
    }
    return 0;
}