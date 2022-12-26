//xdoj0037.c
#include<stdio.h>
void InsertionSort(int a[],int length){
    int i,j,t;
    //  1.从第一个元素开始依次取出所有用于比较元素
    for (i=1;i<length;i++){
        // 2.遍历取出前面元素进行比较
        for(j=i;j>0;j--){
            // 3.如果前面一个元素小于当前元素,就交换位置
            if(a[j-1]<a[j]){
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
    scanf("%d",&n);
    int t;
    int evenarr[100];
    int oddarr[100];
    int k=0,v=0;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t%2==0){//偶数
            evenarr[k++]=t;
        }else{
            oddarr[v++]=t;
        }
    }
    InsertionSort(evenarr,k);
    InsertionSort(oddarr,v);
    for(int i=0;i<k;i++){
        printf("%d ",evenarr[i]);
    }
    for(int i=0;i<v;i++){
        printf("%d ",oddarr[i]);
    }
    return 0;
}