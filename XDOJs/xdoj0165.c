//xdoj0165.c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int max=-9999;
    int nums[80];
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        if(nums[i]>=max){
            max=nums[i];
            t=i;
        }
    }
    printf("%d %d %d",n,max,t);
    return 0;
}