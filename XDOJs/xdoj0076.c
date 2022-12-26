//xdoj0076.c
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
    int n;
    int nums[30]={0};
    scanf("%d",&n);
    if(n>5&&n<30){
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        InsertionSort(nums,n);
        int count=1;
        for(int i=0;i<n;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }else{
                printf("%d:%d\n",nums[i],count);
                count=1;
            }
        }
    }
    return 0;
}