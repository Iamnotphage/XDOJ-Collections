//xdoj0021.c
#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int num[5];
    for(int i=0;i<5;i++){
        num[i]=a%10;
        a/=10;
    }
    for(int j=4;j>=0;j--){
        printf("%d ",num[j]);
    }
    return 0;
}