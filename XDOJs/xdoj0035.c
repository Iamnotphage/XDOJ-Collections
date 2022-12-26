//xdoj0035.c
#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int nums[1000];
    int flag,k=0,t;
    if(n&1!=0){//不是偶数
        return 0;
    }else{
        //生成质数表
        for(int i=2;i<n;i++){
            flag=1;
            for(int j=2;j<=sqrt((double)i);j++){
                if(i%j==0){
                    flag=0;
                }
            }
            if(flag){
                nums[k++]=i;//k最终代表k+1个质数
            }
        }
        //分解偶数
        for(int i=k;i>=(double)k/2;i--){
            t=n-nums[i];
            for(int j=0;j<=(double)k;j++){
                if(t==nums[j]){
                    printf("%d %d",nums[j],nums[i]);
                    goto a;
                }
            }
        }
        a:;
    }
    return 0;
}