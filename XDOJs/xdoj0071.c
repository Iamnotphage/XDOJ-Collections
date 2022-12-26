//xdoj0071.c
#include<stdio.h>
void FindNeighbor(int *judge,int a[20][20],int x,int y){
    //四个方向搜索,注意向左和向上越界会出现意想不到的错误
    if(x!=0&&a[x-1][y]>0&&a[x-1][y]!=a[x][y]){//上
        judge[a[x-1][y]]++;
    }
    if(y!=0&&a[x][y-1]>0&&a[x][y-1]!=a[x][y]){//左
        judge[a[x][y-1]]++;
    }
    if(a[x+1][y]>0&&a[x+1][y]!=a[x][y]){//下
        judge[a[x+1][y]]++;
    }
    if(a[x][y+1]>0&&a[x][y+1]!=a[x][y]){//右
        judge[a[x][y+1]]++;
    }
}
int main(){
    int n,m,t,k,count=0,flag=0;
    scanf("%d%d%d%d",&n,&m,&t,&k);
    int a[20][20]={0};
    int startx,starty,endx,endy;//用于记录目标k的起止位置
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==k&&flag==0){//找到目标k的开始位置
                startx=i;
                starty=j;
                flag=1;//只执行一次
            }
            //找到目标k的终点位置，有几种大情况：最左边，最右边，在中间,最下面，最上面
            //但由于越界部分是0，而矩阵里面的数字不可能是0，所以下式包含所有情况
            if(a[i][j]==k&&a[i][j+1]!=k&&a[i+1][j]!=k){
                endx=i;
                endy=j;
            }
        }
    }
    int judge[50]={0};//索引是t，judge[t]=目标k周边出现的次数,为0代表没有相邻
    for(int i=startx;i<=endx;i++){
        for(int j=starty;j<=endy;j++){
            FindNeighbor(judge,a,i,j);
        }
    }
    for(int i=0;i<=t;i++){
        if(i!=k&&judge[i]!=0){//非0的 就是相邻的
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
