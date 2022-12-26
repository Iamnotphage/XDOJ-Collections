//xdoj0238.c
#include<stdio.h>
int main(){
    int num[4][5];
    int rmax[4],cmin[5];
    int t=0,i,j;
    for(i=0;i<4;i++){
        t=-2147483648;
        for(j=0;j<5;j++){
            scanf("%d",&num[i][j]);
            if(t<num[i][j]){
                t=num[i][j];
                rmax[i]=j;
            }
        }
    }
    //2^31-1
    for(i=0;i<5;i++){
        t=2147483647;
        for(j=0;j<4;j++){
            if(num[j][i]<t){
                t=num[j][i];
                cmin[i]=j;
            }
        }
        if(i==rmax[cmin[i]]){
            printf("%d %d %d",num[cmin[i]][rmax[cmin[i]]],cmin[i]+1,rmax[cmin[i]]+1);
            return 0;
        }

    }
    printf("°°µã²»´æÔÚ");
    return 0;
}