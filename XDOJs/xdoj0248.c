//xdoj0248.c
#include<stdio.h>
int main(){
    int m,n,p,k,d;
    scanf("%d%d%d",&m,&p,&n);
    int total=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&k,&d);
        total-=k*d;
        m+=k;
    }
    printf("%d",total+m*d);
    return 0;
}