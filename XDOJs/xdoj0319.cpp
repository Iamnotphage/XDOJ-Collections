//xdoj0319.cpp
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

int DLR[100],LDR[100];

//插入x到T中，T传引用，避免传值导致返回时T实际上没有改变
void InsertTNode(BiTree& T,int x){
    T=(BiTree)malloc(sizeof(BiTNode));
    T->data=x;
    T->lchild=NULL;
    T->rchild=NULL;
}

int FindRoot(int n,int start,int end){
    //在俩个遍历结果中 找到LDR根结点的位置
    int flag=0,i,j;
    for(i=0;i<n;++i){
        for(j=start;j<=end;++j){
            if(LDR[j]==DLR[i]){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    return j;//返回LDR的索引j
}

BiTree CreateBiTree(BiTree T,int n,int start,int end){
    //下面是终止条件 start和end都是LDR的索引
    if(start>end){
        //这种情况，明显不对头，直接返回
        return T;//会有这种情况，是下面递归的锅，可以先筛掉
    }else if(start==end){
        //说明LDR子数组只剩一个，直接插入结点 然后返回就行了
        InsertTNode(T,LDR[start]);
        return T;
    }

    //这里是找ROOT结点用于插入到树中 先遍历LEVEL，再从LDR子数组中找
    int j=FindRoot(n,start,end);
    InsertTNode(T,LDR[j]);
    T->lchild=CreateBiTree(T->lchild,n,start,j-1);
    T->rchild=CreateBiTree(T->rchild,n,j+1,end);
    return T;
}

int SumTree(BiTree& T){
    //返回值是根结点的值，这样利于递归
    if(T->lchild==NULL && T->rchild==NULL){
        //满二叉树，不用考虑只有左孩子或者右孩子的情况
        int root=T->data;
        T->data=0;
        return root;
    }else{
        //相当于把结果存到边上
        int l=SumTree(T->lchild);
        int r=SumTree(T->rchild);
        int root=T->data;
        //因为相当于结果存在边上，所以左右结点还要加一次
        T->data=l + r + T->lchild->data + T->rchild->data;
        return root;
    }
}

void PostOrder(BiTree T){
    if(T==NULL){
        return;
    }else{
        PostOrder(T->lchild);
        cout<<T->data<<" ";
        PostOrder(T->rchild);
    }
    return;
}

int main(){
    BiTree T=NULL;
    int n;
    //input部分
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>DLR[i];
    }
    for(int i=0;i<n;++i){
        cin>>LDR[i];
    }

    T=CreateBiTree(T,n,0,n-1);
    SumTree(T);
    PostOrder(T);

    return 0;
}