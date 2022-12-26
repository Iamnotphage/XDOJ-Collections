//xdoj0271.cpp
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

BiTree CreateBSTree(BiTree T,int x){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=x;
        T->lchild=NULL;
        T->rchild=NULL;
    }else{
        if(x>T->data){
            T->rchild=CreateBSTree(T->rchild,x);
        }else if(x< T->data){
            T->lchild=CreateBSTree(T->lchild,x);
        }
    }
    return T;
}

void InOrder(BiTree T){
    //LDR中序遍历
    if(T==NULL){
        return;
    }else{
        InOrder(T->lchild);
        cout<<T->data<<' ';
        InOrder(T->rchild);
    }
}

int main(){
    BiTree T=NULL;
    int n,t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t;
        T=CreateBSTree(T,t);
    }

    InOrder(T);

    return 0;
}