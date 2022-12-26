//xdoj0094.c
#include<stdio.h>
int main(){
    int a[4];
    int min,t,i,j;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<3;i++){//选择排序
        for(j=i+1,min=i;j<4;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    for(int i=0;i<4;i++){
        printf("%d ",a[i]);
    }
    return 0;
}