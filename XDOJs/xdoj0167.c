//xdoj0167.c
#include<stdio.h>
struct list{
    int data;
    int count;
};
void swap(struct list*a,struct list* b){
    struct list t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n;
    scanf("%d",&n);
    struct list nums[1005]={0};//改成1000会超时
    for(int i=0;i<1005;i++){
        nums[i].data=-1;//初始化
    }
    int i,j,maxlen=0,t,max;
    for(i=0;i<n;i++){
        scanf("%d",&t);
        if(t>1000||t<0){
            return 0;
        }
        nums[t].data=t;
        nums[t].count++;
        if(maxlen<t){
            maxlen=t;
        }
    }
    for(i=0;i<=maxlen-1;i++){
        if(nums[i].data==-1){
            continue;
        }
        for(j=i+1,max=i;j<=maxlen;j++){
            if(nums[i].data!=-1){
                if(nums[j].count>nums[max].count){
                    max=j;
                }else if(nums[j].count==nums[max].count){
                    if(nums[j].data<nums[max].data){//值小的排前面
                        max=j;
                    }
                }
            }
        }
        if(max!=i){
            swap(&nums[max],&nums[i]);
        }
    }
    for(i=0;i<=maxlen;i++){
        if(nums[i].data!=-1){
            printf("%d %d\n",nums[i].data,nums[i].count);
        }
    }
    return 0;
}