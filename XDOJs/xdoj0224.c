//xdoj0224.c xdoj0162一样
#include<stdio.h>
int main(){
    int a[2][3];
    int b[3][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int c1=a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0];
    int c2=a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1];
    int c3=a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0];
    int c4=a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1];
    printf("%d %d\n%d %d",c1,c2,c3,c4);
    return 0;
}