//xdoj0264.c
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;

LinkList InitLinkList(){
    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return L;
}

void DisplayLinkList(LinkList L){
    LinkList p=L->next;
    while(p->next!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}

int main(){
    LinkList Ls[100];// 足够大的指针数组
    int n,length,tmp;

    scanf("%d",&n);

    //直接构造反转链表
    for(int i=0;i<n;i++){
        Ls[i]=InitLinkList();
        scanf("%d",&length);
        for(int j=0;j<length;j++){
            scanf("%d",&tmp);
            LinkList p=Ls[i];//p始终指向头结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->data=tmp;

            s->next=p->next;
            p->next=s;
        }
    }
    //输出
    for(int i=0;i<n-1;i++){
        DisplayLinkList(Ls[i]);
        printf("\n");
    }
    DisplayLinkList(Ls[n-1]);

    return 0;
}