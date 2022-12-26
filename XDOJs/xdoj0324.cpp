//xdoj0324.cpp
#include<iostream>
#include<queue>
#define MAX_VEX_NUM 100
using namespace std;

typedef struct MGraph{
    int adj[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum;
}MGraph;

bool visited[MAX_VEX_NUM];

void DFS(MGraph G,int v){
    //从第v个结点出发DFS遍历图G
    visited[v]=true;
    for(int w=0;w<G.vexnum;++w){
        if(!visited[w] && G.adj[v][w]){
            DFS(G,w);
        }
    }
}

void DFSTraverse(MGraph G){
    int omega=0;//连通分量
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;//初始化为false
    }
    for(int i=0;i<G.vexnum;++i){
        if(!visited[i]){
            DFS(G,i);
            omega++;
        }
    }
    cout<<endl<<omega;
}

void BFSTraverse(MGraph G){
    for(int i=0;i<G.vexnum;++i){
        visited[i]=false;//初始化visited
    }
    queue<int> Q;
    for(int v=0;v<G.vexnum;++v){
        if(!visited[v]){
            visited[v]=true;
            cout<<v+1<<" ";
            Q.push(v);
            while(!Q.empty()){
                int u=Q.front();
                Q.pop();
                for(int w=0;w<G.vexnum;++w){
                    if(!visited[w] && G.adj[u][w]){
                        visited[w]=true;
                        cout<<w+1<<" ";
                        Q.push(w);
                    }
                }
            }
        }
    }
}

int main(){
    MGraph G;
    cin>>G.vexnum;
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;++j){
            cin>>G.adj[i][j];
        }
    }
    BFSTraverse(G);
    DFSTraverse(G);//为了计算连通分量omega
    return 0;
}