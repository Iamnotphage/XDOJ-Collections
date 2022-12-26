//xdoj0075.c
#include<stdio.h>
int main(){
    int m,n,a[256][256],res[16]={0};
    scanf("%d%d",&m,&n);
    if(m>=0&&m<=256&&n>=0&&n<=256){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                res[a[i][j]]++;
            }
        }
        for(int i=0;i<16;i++){
            if(res[i]!=0)
            printf("%d %d\n",i,res[i]);
        }
    }
    return 0;
}