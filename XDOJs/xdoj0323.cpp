//xdoj0323.cpp
#include<cstdio>
#include<stack>
#define MAX_VEX_NUM 100
using namespace std;

typedef struct MGraph{
    int adj[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum;
}MGraph;

int visited[MAX_VEX_NUM];//三个状态 -1正在访问，0未访问，1已经访问
int hasRing[MAX_VEX_NUM];
int pos=0;

void DFS(MGraph G,int v){
    visited[v]=-1;//正在访问
    for(int w=0;w<G.vexnum;++w){
        if(visited[w]==-1 && G.adj[v][w]){
            //正在访问的点又被访问，说明有回路
            hasRing[pos]=1;
        }else if(visited[w]==0 && G.adj[v][w]){
            //未被访问，且v到w有路径，则继续dfs
            DFS(G,w);
        }//v和w不相邻就继续刷新w
    }
    visited[v]=1;//已经访问结束 也就是不在程序栈中了
}

void DFSTraverse(MGraph G){
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;
    }
    for(int i=0;i<G.vexnum;++i){
        if(visited[i]==0){
            DFS(G,i);
        }
    }
}

void InitGraph(MGraph& G){
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;++j){
            scanf("%d",&G.adj[i][j]);
        }
    }
}

//除了拓扑排序还可以dfs
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        MGraph G;
        scanf("%d",&G.vexnum);
        InitGraph(G);
        DFSTraverse(G);
        pos++;
    }
    for(int i=0;i<n;++i){
        printf("%d",hasRing[i]);
    }
    return 0;
}

//another version
int indegree[MAX_VEX_NUM];//各个结点的入度值

//先对各顶点求入度
void FindInDegree(MGraph G,int indegree[]){
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;++j){
            if(G.adj[i][j]!=0){
                indegree[j]++;
            }
        }
    }
}

bool TopologicalSort(MGraph G,int indegree[]){
    FindInDegree(G,indegree);//对各顶点求入度
    stack<int> S;//这里的容器改成queue也行
    for(int i=0;i<G.vexnum;++i){
        if(!indegree[i]){
            S.push(i);//入度为0，进入S
        }
    }
    int count=0;//对输出顶点计数
    while(!S.empty()){
        int u=S.top();
        S.pop();
        for(int w=0;w<G.vexnum;++w){
            if(G.adj[u][w]!=0){
                indegree[w]--;
                if(indegree[w]==0){
                    S.push(w);
                }
            }
        }
        count++;
    }
    if(count<G.vexnum){
        return false;//TopoSort失败 有环
    }else{
        return true;//TopoSort成功
    }
}