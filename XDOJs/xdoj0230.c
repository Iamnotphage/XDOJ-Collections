//xdoj0230.c
#include<stdio.h>
#include<math.h>
int fun(int y[],int x){
    int flag=1,k=0;
    for(int i=2;i<=x;i++){
        flag=1;
        for(int j=2;j<=sqrt((double)i);j++){
            if(i%j==0){
                flag=0;
            }
        }
        if(flag){
            y[k++]=i;
        }
    }
    return k;
}
int main(){
    int x;
    int y[1000];
    scanf("%d",&x);
    printf("%d\n",fun(y,x));
    for(int i=0;i<fun(y,x);i++){
        printf("%d ",y[i]);
    }
    return 0;
}