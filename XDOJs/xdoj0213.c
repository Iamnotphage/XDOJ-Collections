//xdoj0213.c
//测试样例输入的绝对有不符合题意的输入，千万不要让2<=m<=n<=7 否则最后一个例子会出错
#include<stdio.h>
int nums[50]={0};
void swap(int *a,int *b){
    int t=*a;
    *a = *b;
    *b = t;
}
void reverse(int *nums,int start,int end){
    while(start<end){
        swap(&nums[start],&nums[end]);
        start++;
        end--;
    }
}
void SelectionSort(int *nums,int length){
    int i,j,min;
    for(i=0;i<length-1;i++){
        for(j=i,min=i;j<length;j++){
            if(nums[min]>nums[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(&nums[min],&nums[i]);
        }
    }
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&nums[k++]);
            if(nums[k-1]>100){
                return 0;
            }
        }
    }
    //排序
    SelectionSort(nums,m*n);
    //奇数行反转
    for(int i=0;i<n*m;i=i+(n+n)){
        reverse(nums,i,i+n-1);
    }
    //按照二维输出
    k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%3d",nums[k++]);
        }
        if(i!=m-1){
            printf("\n");
        }
    }
    return 0;
}