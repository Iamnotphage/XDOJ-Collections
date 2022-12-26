//xdoj0030.c
#include<stdio.h>
int main(){
    unsigned int a,b;
    int sum=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        sum=i;
        for(int j=1;j<i/2+1;j++){
            if(i%j==0){
                sum-=j;
            }
        }
        if(sum==0){
            printf("%d\n",i);
        }
    }
    return 0;
}