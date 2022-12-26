//xdoj0156.c
#include<stdio.h>
int main(){
    int count=0;
    for(int i=100;i<=500;i++){
        if(i%77!=0&&(i%7==0||i%11== 0)){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}