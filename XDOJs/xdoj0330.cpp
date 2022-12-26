//xdoj0330.cpp
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

void FindFater(BiTree T,int x){
    //在二叉排序树T中找到x的父亲
    if(T==NULL){
        return;
    }else{
        if(x==T->data){
            //是根结点，直接输出-1
            cout<<"-1"<<endl;
        }else if(x > T->data){
            if(x==T->rchild->data){
                cout<<T->data<<endl;
            }else{
                FindFater(T->rchild,x);
            }
        }else if(x < T->data){
            if(x==T->lchild->data){
                cout<<T->data<<endl;
            }else{
                FindFater(T->lchild,x);
            }
        }
    }
    return;
}

int main(){
    BiTree T=NULL;
    int n,t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t;
        T=CreateBSTree(T,t);
        FindFater(T,t);
    }
    return 0;
}