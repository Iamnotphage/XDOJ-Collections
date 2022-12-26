//xdoj0086.c
#include<stdio.h>
const int width=101;
void draw(int xoy[101][101],int x1,int y1,int x2,int y2){
    for(int x=x1;x<x2;x++){
        for(int y=y1;y<y2;y++){
            if(xoy[x][y]==0){
                xoy[x][y]=1;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int xoy[width][width]={0};
    int x1,y1,x2,y2;
    int maxx=0,maxy=0;
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        draw(xoy,x1,y1,x2,y2);
        if(maxx<x2){
            maxx=x2;
        }
        if(maxy<y2){
            maxy=y2;
        }
    }
    int count=0;
    for(int i=0;i<=maxx;i++){
        for(int j=0;j<=maxy;j++){
            if(xoy[i][j]==1){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}