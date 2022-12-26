//xdoj0176.c
#include<stdio.h>
const int maxn=1000;
int main(){
    int n;
    scanf("%d",&n);
    int mid=-1,c1=0,c2=0;
    int nums[maxn];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(int i=0;i<n;i++){
        c1=0;
        c2=0;
        for(int j=0;j<n;j++){
            if(nums[i]<nums[j]){
                c1++;
            }else if(nums[i]>nums[j]){
                c2++;
            }
        }
        if(c1==c2){
            mid=nums[i];
            break;
        }
    }
    printf("%d",mid);
    return 0;
}