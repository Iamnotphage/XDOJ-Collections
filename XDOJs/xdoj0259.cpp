//xdoj0259.cpp
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
        if(x < T->data){
            T->lchild=CreateBSTree(T->lchild,x);
        }else if(x > T->data){
            T->rchild=CreateBSTree(T->rchild,x);
        }
    }
    return T;
}

void PreOrder(BiTree T){
    if(T==NULL)return;
    cout<<T->data<<" ";
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    return;
}

void PostOrder(BiTree T){
    if(T==NULL)return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    cout<<T->data<<" ";
    return;
}

int main(){
    BiTree T=NULL;
    int n,input[100];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>input[i];
    }
    for(int i=0;i<n;++i){
        T=CreateBSTree(T,input[i]);
    }
    PreOrder(T);
    cout<<endl;
    PostOrder(T);
    return 0;
}