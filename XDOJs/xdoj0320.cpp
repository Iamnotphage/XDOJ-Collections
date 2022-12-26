//xdoj0320.cpp
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

int LEVEL[100],LDR[100];

//插入x到T中，T传引用，避免传值导致返回时T实际上没有改变
void InsertTNode(BiTree& T,int x){
    T=(BiTree)malloc(sizeof(BiTNode));
    T->data=x;
    T->lchild=NULL;
    T->rchild=NULL;
}

int FindRoot(int n,int start,int end){
    int flag=0,i,j;
    for(i=0;i<n;++i){
        for(j=start;j<=end;++j){
            if(LDR[j]==LEVEL[i]){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    return j;
}

BiTree CreateBiTree(BiTree T,int n,int start,int end){
    //下面是终止条件 start和end都是LDR的索引
    if(start>end){
        //这种情况，明显不对头，直接返回
        return T;//会有这种情况，是下面递归的锅，可以先筛掉
    }else if(start==end){
        //说明LDR子数组只剩一个，直接插入结点 然后返回就行了
        InsertTNode(T,LDR[start]);
        //这里输出的是叶子结点
        //因为此时start已经等于end，说明这里直接插入一个结点并且往后不会有结点是他的孩子
        cout<<T->data<<" ";
        return T;
    }
    //这里是找ROOT结点用于插入到树中 先遍历LEVEL，再从LDR子数组中找
    int j=FindRoot(n,start,end);
    InsertTNode(T,LDR[j]);
    T->lchild=CreateBiTree(T->lchild,n,start,j-1);
    T->rchild=CreateBiTree(T->rchild,n,j+1,end);
    return T;
}

void PreOrder(BiTree T){
    if(T==NULL){
        return;
    }else{
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return;
}

void PostOrder(BiTree T){
    if(T==NULL){
        return;
    }else{
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data<<" ";
    }
    return;
}

int main(){
    BiTree T=NULL;
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>LEVEL[i];
    }
    for(int i=0;i<n;++i){
        cin>>LDR[i];
    }

    T=CreateBiTree(T,n,0,n-1);

    cout<<endl;
    PreOrder(T);
    cout<<endl;
    PostOrder(T);

    return 0;
}