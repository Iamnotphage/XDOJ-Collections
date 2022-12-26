//xdoj0006.c
#include<stdio.h>
void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int main(){
    int n,t,sum=0;
    scanf("%d",&n);
    int nums[2][1000]={0};
    //输入
    for(int i=0;i<n;i++){
        scanf("%d",&nums[0][i]);
    }
    //计算各位数字之和
    for(int i=0;i<n;i++){
        sum=0;
        t=nums[0][i];
        while(t!=0){
            sum=sum+t%10;
            t/=10;
        }
        nums[1][i]=sum;
    }
    //各位数之和从小到大排序
    int i,j,min;
    for(i=0;i<n-1;i++){
        for(j=i+1,min=i;j<n;j++){
            if(nums[1][min]>nums[1][j]){
                min=j;
            }else if(nums[1][min]==nums[1][j]){//如果相同，按照从小到大的顺序排序
                if(nums[0][min]<nums[0][j]){
                    swap(&nums[1][j],&nums[1][min]);
                    swap(&nums[0][j],&nums[0][min]);
                }
            }
        }
        if(i!=min){
            swap(&nums[1][i],&nums[1][min]);
            swap(&nums[0][i],&nums[0][min]);
        }
    }
    //输出
    for(i=n-1;i>=0;i--){
        printf("%d %d\n",nums[0][i],nums[1][i]);
    }
    return 0;
}