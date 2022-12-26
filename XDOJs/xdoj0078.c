//xdoj0078.c
#include<stdio.h>
int main(){
    int n,m,c,count=0,flag=0;
    scanf("%d%d%d",&n,&m,&c);
    char net[20][20]={'\0'};
    for(int i=0;i<n;i++){
        scanf("%s",net[i]);
    }
    int x=0,y=c-1;//x,y表示机器人所在行列(从0起始)
    int b[20][20]={0};//走过的路线变为1
    while(x<n&&x>=0&&y>=0&&y<m){
        if(b[x][y]==1){//如果走过这个格子
            flag=1;
            printf("loop %d",count);
            break;
        }
        switch(net[x][y]){
            case 'W':
                b[x][y]=!b[x][y];
                y--;
                count++;
                break;
            case 'E':
                b[x][y]=!b[x][y];
                y++;
                count++;
                break;
            case 'N':
                b[x][y]=!b[x][y];
                x--;
                count++;
                break;
            case 'S':
                b[x][y]=!b[x][y];
                x++;
                count++;
                break;
        }

    }
    if(!flag){
        printf("out %d",count);
    }
    return 0;
}