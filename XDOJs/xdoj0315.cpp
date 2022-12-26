//xdoj0315.cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

typedef struct BTNode{
    char data;
    struct BTNode* lchild;
    struct BTNode* rchild;
}BTNode,*BiTree;

BiTree PreOrderCreateBT(){
    char ch;
    BiTree T;
    scanf("%c",&ch);
    if(ch=='#'){//用空格表示空树
        T=NULL;
    }else{
        if(!(T=(BiTree)malloc(sizeof(BTNode)))){
            exit(0);
        }
        T->data=ch;//生成根结点
        T->lchild=PreOrderCreateBT();
        T->rchild=PreOrderCreateBT();
    }
    return T;
}

void InOrder(BiTree T){
    //LDR
    if(T==NULL){
        return;
    }else{
        InOrder(T->lchild);
        cout<<T->data<<' ';
        InOrder(T->rchild);
    }
}

int main(){
    BiTree T;
    T=PreOrderCreateBT();
    InOrder(T);
    return 0;
}