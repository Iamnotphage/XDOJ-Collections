//xdoj0067.c
#include<stdio.h>
int main(){
    int n,target;
    scanf("%d%d",&n,&target);
    int nums[100];
    int flag=0;
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        if(nums[i]==target){
            printf("%d ",i);
            flag=1;
        }
    }
    if(flag==0){
        printf("-1");
    }
    return 0;
}