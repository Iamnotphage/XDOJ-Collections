//xdoj0210.c 题目输出样例有错
#include<stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void change(int *num,int length){
    int max=0,min=0;
    for(int i=1;i<length;i++){
        if(num[i]>num[max]){
            max=i;
        }
        if(num[i]<num[min]){
            min=i;
        }
    }
    swap(&num[min],&num[max]);
}
int main(){
    int num[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    change(num,n);
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    return 0;
}