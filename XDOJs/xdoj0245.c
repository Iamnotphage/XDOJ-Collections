//xdoj0245.c
#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    int lights[100]={0};
    for(i=1;i<=m;i++){//i是人的编号
        for(j=1;j<=n;j++){//j是灯的编号
            if(j%i==0){
                lights[j]=!lights[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(lights[i]){
            printf("%d ",i);
        }
    }
    return 0;
}