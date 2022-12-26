//xdoj0174.c
#include<stdio.h>

int w[201]={0},dp[201][2001]={0};

int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,V=0,i,j;//V 表示总价值
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        V+=w[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=V/2;j++){
            if(w[i]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
            }
            //printf("dp[%d][%d]:%d \n",i,j,dp[i][j]);
        }
    }
    int SumA=dp[n][V/2];
    printf("%d",V-2*SumA);
    return 0;
}