//xdoj0300.c
#include<stdio.h>
int main(){
    int n;
    int count=0;
    scanf("%d",&n);
    if(n!=0){
        while(n<=999999999&&n>0){
            n/=10;
            count++;
        }
        printf("%d",count);
    }else{//没0的情况会只有75分
        printf("%d",1);
    }
    return 0;
}