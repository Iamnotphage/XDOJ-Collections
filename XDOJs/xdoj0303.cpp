//xdoj0303.cpp
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX_VEX_NUM 30
using namespace std;

typedef struct MGraph{
    int adj[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum;//结点数
    int arcnum;//边数
}MGraph;

bool visited[MAX_VEX_NUM];
int vexnums[MAX_VEX_NUM];//各个连通图的顶点个数
int pos=0;//控制vexnums数组的指针

void DFS(MGraph G,int v){
    visited[v]=true;
    vexnums[pos]++;
    for(int w=0;w<G.vexnum;++w){
        if(!visited[w]&&G.adj[v][w]){
            DFS(G,w);
        }
    }
}

void DFSTraverse(MGraph G,int& omega){
    omega=0;
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;
    }
    for(int i=0;i<G.vexnum;++i){
        if(!visited[i]){
            DFS(G,i);
            omega++;
            pos++;//指向下一个连通分量
        }
    }
}

int main(){
    MGraph G;
    int i,j,omega;
    scanf("%d%d",&G.vexnum,&G.arcnum);
    
    for(i=0;i<G.vexnum;++i){
        for(j=0;j<G.vexnum;++j){
            G.adj[i][j]=0;
        }
        vexnums[i]=0;
    }

    for(int v=0;v<G.arcnum;++v){
        scanf("%d%d",&i,&j);
        G.adj[i-1][j-1]=1;
        G.adj[j-1][i-1]=1;//无向图,对称
    }

    DFSTraverse(G,omega);
    printf("%d\n",omega);

    sort(vexnums,vexnums+omega);

    for(int i=0;i<omega;++i){
        printf("%d ",vexnums[i]);
    }
    return 0;
}