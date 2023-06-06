# XDOJ-Collections🐹

![](https://img.shields.io/github/repo-size/Iamnotphage/XDOJ-Collections) ![](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue) ![](https://img.shields.io/github/stars/Iamnotphage/XDOJ-Collections?style=social)

Dedicated to collecting all XDOJs 

目前已收录240/??? 2022-12-27

所有源码均AC通过oj(不排除抽风oj更改测试样例导致无法AC的情况)

# Brief-Introduction🐹
XDOJ is a online judge platform from Xidian University. 

There are some C/C++ problems.😁

This project aimes to collect all the XDOJs and share them for free.😊

# How to use🐹

Step1 Search for questions🤤

Step2 Download it😎

# Preview🐹
XDOJ0002.c for example.😍
```C
//xdoj0002.c
#include<stdio.h>
int main(){
    unsigned int n;
    unsigned int count=0;
    unsigned int a;
    scanf("%d",&n);
    int num[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        num[i]=a;
    }
    for(int j=0;j<n;j++){
        if(num[j]!=num[j+1]){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
```

XDOJ0259.cpp for example.😍

```CPP
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
```
