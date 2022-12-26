//xdoj0332.cpp
#include<iostream>
#include<cstdlib>
using namespace std;

int Matrix[1000][3];//直接矩阵存储，不需要非线性结构了

int DFS(int root,int rootval){
    //从root开始DFS
    int tmp;
    if(root==0){
        //终止条件，也就是遇到空树
        return -1;//设置一个标志，表示该根结点下方无孩子
    }else{
        tmp=DFS(Matrix[root][1],Matrix[Matrix[root][1]][0]);
        if(tmp!=-1 && tmp >= rootval){
            //如果左孩子的结点大于等于根，说明不是合法的二叉排序树
            cout<<"false";
            exit(0);//直接退出
        }
        tmp=DFS(Matrix[root][2],Matrix[Matrix[root][2]][0]);
        if(tmp!=-1 && tmp <= rootval){
            //如果右孩子的结点小于等于根，说明不是合法的二叉排序树
            cout<<"false";
            exit(0);
        }
    }
    if(tmp==-1){
        //说明该根的左右子树都是空，返回的应该是根的值
        tmp=rootval;
    }
    return tmp;
}


int main(){
    //实际上是DFS深度优先搜索，左子树搜一遍，没有大于根的就回头，再根再右子树
    int n,root;
    for(int i=0;i<3;++i){
        Matrix[0][i]=0;//第0行不存储
    }

    cin>>n>>root;
    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            cin>>Matrix[i][j];//行从1数起，避免混淆
        }
    }
    DFS(root,Matrix[root][0]);
    cout<<"true";

    return 0;
}