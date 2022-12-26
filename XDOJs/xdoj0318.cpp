//xdoj0318.cpp
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

char DLR[27],LDR[27];
//插入x到T中，T传引用，避免传值导致返回时T实际上没有改变
void InsertTNode(BiTree& T,char x){
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

void PostOrder(BiTree T){
    if(T==NULL){
        return;
    }else{
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c",T->data);
    }
}

int main(){
    BiTree T;
    char ch;
    int i=0;
    while(scanf("%c",&ch) && ch!='\n'){
        DLR[i++]=ch;
    }
    gets(LDR);//???没懂为什么这里改成gets过了
    T=CreateBiTree(T,i,0,i-1);
    PostOrder(T);
    return 0;
}