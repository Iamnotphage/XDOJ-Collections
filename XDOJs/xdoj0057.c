//xdoj0057.c
#include<stdio.h>
int fib(int n){
    int f0=7,f1=11,t;
    if(n==0){
        return f0;
    }else if(n==1){
        return f1;
    }else{
        for(int i=1;i<n;i++){
            t=f0+f1;
            f0=f1;
            f1=t;
        }
        return f1;
    }
}
int main(){
    printf("%d",fib(2));
    return 0;
}