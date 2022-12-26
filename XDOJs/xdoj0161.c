//xdoj0161.c
#include<stdio.h>
int main(){
    int n;
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            c1++;
        }else if(i%2==0){
            c2++;
        }
        if(i%3==0)c3++;
        if(i%5==0)c4++;
        if(i%7==0)c5++;
    }
    printf("%d %d %d %d %d",c1,c2,c3,c4,c5);
    return 0;
}