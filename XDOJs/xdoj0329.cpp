//xdoj0329.cpp
#include<cstdio>
#include<cstdlib>
using namespace std;

int pos=0;//计数器

typedef struct BiTNode{
    char data;//因题而异
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

BiTree CreateBSTree(BiTree T,char x){
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

//将T前序遍历的结果存储到数组a
void PreOrder(BiTree T,char a[]){
    if(T==NULL){
        return;
    }else{
        a[pos++]=T->data;
        PreOrder(T->lchild,a);
        PreOrder(T->rchild,a);
    }
    return;
}

//将T中序遍历的结果存储到数组a
void InOrder(BiTree T,char a[]){
    if(T==NULL){
        return;
    }else{
        InOrder(T->lchild,a);
        a[pos++]=T->data;
        InOrder(T->rchild,a);
    }
    return;
}

void CompareTree(char pre1[],char pre2[],char in1[],char in2[],int length){
    for(int i=0;i<length;++i){
        if(pre1[i]!=pre2[i]){
            printf("NO\n");
            return;
        }
    }
    for(int i=0;i<length;++i){
        if(in1[i]!=in2[i]){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    return;
}

void Fun(int n){
    BiTree T1=NULL;
    int i,length;
    char str1[11];//输入的字符串
    char pre1[10],pre2[10],in1[10],in2[10];//最终对比的前序和中序结果
    scanf("%s",str1);
    for(i=0;str1[i]!='\0';++i){
        T1=CreateBSTree(T1,str1[i]);
    }

    PreOrder(T1,pre1);
    pos=0;
    InOrder(T1,in1);
    pos=0;

    //此时i为str1的长度
    length=i;

    for(int j=0;j<n;++j){
        char str2[11];//避免循环过后仍然存在值
        BiTree T2=NULL;//避免循环过后仍然存在树
        scanf("%s",str2);
        for(i=0;i<length;++i){
            T2=CreateBSTree(T2,str2[i]);
        }
        PreOrder(T2,pre2);
        pos=0;
        InOrder(T2,in2);
        pos=0;
        CompareTree(pre1,pre2,in1,in2,length);
    }    
}

int main(){
    int n;
    //xdoj非要加个最后一行是0，最后一个测试样例是多次输入n判断,纯属啥比
    while(scanf("%d",&n) && n!=0){
        Fun(n);
    }
    return 0;
}