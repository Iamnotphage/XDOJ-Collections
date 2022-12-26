//xdoj0200.c
#include<stdio.h>
int main(){
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    int p;
    scanf("%d",&p);
    if(p>=0&&p<10){
        for(int i=p+1;i<10;i++){
        printf("%d ",array[i]);
        }
        for(int i=0;i<=p;i++){
        printf("%d ",array[i]);
        }
    }
    return 0;
}