//xdoj0225.c
#include<stdio.h>
int main(){
    int mat[3][3],matt[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&mat[i][j]);
            matt[i][j]=mat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matt[i][j]=mat[i][j]+mat[j][i];
            printf("%d ",matt[i][j]);
        }
        printf("\n");
    }
    return 0;
}