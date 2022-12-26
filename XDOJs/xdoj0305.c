//xdoj0305.c
#include<stdio.h>

//123...n的初始栈，弹出的顺序必定部分递减
//也就是说，弹出序列中 任意第i个数往后，小于这个数的这些数，必然是递减的
//4123 不符合，第一个数是4 小于4的数123不是递减
int Judge(int n,int* nums){
    int flag=0,min;//假设不符合
    for(int i=0;i<n;i++){
        min=nums[i]-1;
        for(int j=i+1;j<n;j++){
            if(min==0){
                //说明第i个元素是1，那么直接跳过
                break;
            }

            if(nums[j]>nums[i]){
                //大于第i个数的忽略
                continue;
            }else if(nums[j] < nums[i]){
                //小于第i个数的数，如果不是递减，直接返回不符合
                if(nums[j]<=min){
                    min=nums[j];//刷新min
                }else{
                    return flag;
                }
            }else if(nums[j]==nums[i]){
                return flag;//绝对不可能的情况
            }
        }
    }
    flag=1;
    return flag;
}

int main(){
    int n,nums[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    if(Judge(n,nums)){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}