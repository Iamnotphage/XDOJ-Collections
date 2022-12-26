//xdoj0040.c
#include<stdio.h>
void InsertionSort(int a[],int length){
    int i,j,t;
    //  1.从第一个元素开始依次取出所有用于比较元素
    for (i=1;i<length;i++){
        // 2.遍历取出前面元素进行比较
        for(j=i;j>0;j--){
            // 3.如果前面一个元素大于当前元素,就交换位置
            if(a[j-1]>a[j]){
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }else{
                break;
            }
        }
    }
}
int main(){
    int nums[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    InsertionSort(nums,n);
    int d=nums[1]-nums[0];
    int t,flag=0;
    for(int i=2;i<n;i++){
        t=nums[i]-nums[i-1];
        if(t==d){
            flag=1;
        }else{
            flag=0;
        }
    }
    if(flag){
        printf("%d",d);
    }else{
        printf("no");
    }
    return 0;
}