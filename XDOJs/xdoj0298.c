//xdoj0298.c
#include<stdio.h>
int main(){
    int a,b,i,j,min,t;
    scanf("%d%d",&a,&b);
    int num[4]={
        (a+b)*(a+b),(a-b)*(a-b),
        a*a+b*b,a*a-b*b
    };
    for(i=0;i<3;i++){
        for(j=i+1,min=i;j<4;j++){
            if(num[min]>num[j]){
                min=j;
            }
        }
        if(min!=i){
            t=num[min];
            num[min]=num[i];
            num[i]=t;
        }
    }
    printf("%d %d",num[3],num[0]);
    return 0;
}