//xdoj0325.cpp
#include<iostream>
#include<stack>
#define MAX_VEX_NUM 100
using namespace std;

typedef struct MatrixGraph{
    int Matrix[MAX_VEX_NUM][MAX_VEX_NUM];//邻接矩阵
    int vexnum;//结点数
}MGraph;

bool visited[MAX_VEX_NUM];//结点是否被遍历过

void DFS(MGraph G,int v){
    //从第v个结点出发DFS遍历图G
    visited[v]=true;
    cout<<v+1<<" ";

    for(int w=0;w<G.vexnum;++w){
        if(!visited[w] && G.Matrix[v][w]){
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

void DepthFirstSearch(MGraph G,int start){
    stack<int> S;//visit stack 存储访问过的结点
    S.push(start);
    visited[start]=1;
    int lineNo=S.top();
    cout<<lineNo+1<<" ";
    while(!S.empty()){
        lineNo=S.top();
        int colNo=0;
        for(colNo=0;colNo<G.vexnum;++colNo){
            if(G.Matrix[lineNo][colNo] && !visited[colNo]){
                S.push(colNo);
                visited[colNo]=true;
                cout<<colNo+1<<" ";
                break;
            }
        }
        if(colNo==G.vexnum){
            S.pop();
        }
    }
}

int main(){
    MGraph G;
    int count=0;
    cin>>G.vexnum;
    for(int i=0;i<G.vexnum;++i){
        for(int j=0;j<G.vexnum;++j){
            cin>>G.Matrix[i][j];
        }
    }
    for(int i=0;i<G.vexnum;++i){
        if(!visited[i]){
           DepthFirstSearch(G,i);
           count++;
        }
    }
    cout<<endl<<count;
    return 0;
}