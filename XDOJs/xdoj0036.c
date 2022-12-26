//xdoj0036.c
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
    int m;
    scanf("%d",&m);
    int arr[20][20];
    int ans[402];//总共有m*m+2个
    int sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //求每行
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        ans[i]=sum;
        sum=0;
    }
    sum=0;
    //求每列
    int t=m;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            sum+=arr[j][i];
        }
        ans[t++]=sum;
        sum=0;
    }
    sum=0;
    //求主对角线
    for(int i=0;i<m;i++){
        sum+=arr[i][i];
    }
    ans[t]=sum;
    //求副对角线
    sum=0;
    for(int i=m-1;i>=0;i--){
        sum+=arr[m-i-1][i];
    }
    ans[t+1]=sum;
    //排序
    InsertionSort(ans,t+2);
    //输出
    for(int i=t+1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    return 0;
}