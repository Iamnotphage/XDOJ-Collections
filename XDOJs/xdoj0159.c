//xdoj0159.c
#include<stdio.h>
float Mul(int m){
    float ans=1;
    for(int i=m;i>1;i--){
        ans*=i;
    }
    return ans;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    if(m>n){
        printf("%.2f",Mul(m)/Mul(n)/Mul(m-n));
    }
    return 0;
}
