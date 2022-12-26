//xdoj0065.c
#include<stdio.h>
int calculate(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    long int n;
    int ans=0;
    scanf("%ld",&n);
    ans=calculate(n);
    while(ans>=10){
        ans=calculate(ans);
    }
    printf("%d",ans);
    return 0;
}