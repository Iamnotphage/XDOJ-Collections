//xdoj0201.c
#include<stdio.h>
int main(){
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
        if(i>=1){
            printf("%d ",a[i]/a[i-1]);
        }
    }
    return 0;
}