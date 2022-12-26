//xdoj0004.c
#include<stdio.h>
#include<string.h>
void InsertionSort(char a[],int length){
    int i,j;
    char t;
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
    char input[256];
    char orders[256]={'\0'};
    int j=0,k,flag=1,sign;//sign是查重的标签
    gets(input);
    for(int i=0;i<strlen(input);i++){
        if(input[i]=='-'&&flag==1){
            orders[j++]=input[i+1];
            flag=0;//只执行一次
        }else if(input[i]=='-'&&flag==0){
            for(k=0;k<strlen(orders);k++){
                if(orders[k]==input[i+1]){//赋值之前先遍历orders看看里面是否已经存在相同的
                    sign=0;
                    break;
                }
            }
            if(sign){//如果不存在相同的，就赋值
                orders[j++]=input[i+1];
            }
            sign=1;
        }
    }
    //排序
    InsertionSort(orders,strlen(orders));
    if(strlen(orders)==0){
        printf("no");
    }else{
        for(int i=0;i<strlen(orders);i++){
            printf("-%c ",orders[i]);
        }
    }
    return 0;
}