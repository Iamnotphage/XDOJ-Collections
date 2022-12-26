//xdoj0223.c  xdoj0190一样
#include<stdio.h>
int main(){
    int a,sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a);
            if(i==j){
                sum+=a;
            }
        }
    }
    printf("%d",sum);
    return 0;
}