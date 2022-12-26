//xdoj0263.c

#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;

//创建头结点
LinkList LinkListInit(){

    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return L;
}

void CreateLinkList(LinkList L,LinkList p,ElemType e){
    LinkList s=(LinkList)malloc(sizeof(LNode));

    s->data=e;

    p->next=s;
    s->next=NULL;
}

void InsertLinkList(LinkList L,ElemType e){
    LinkList p=L;

    //将p移动到插入的空隙 前一个结点
    while(p->next!=NULL && p->next->data < e){
        p=p->next;
    }

    //开始插入
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
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
    int n;
    ElemType e,tmp;
    LinkList L=LinkListInit();
    LinkList pos=L;//动态指针，指向L表最后一个结点，方便创建L

    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        CreateLinkList(L,pos,tmp);
        pos=pos->next;
    }
    // DisplayLinkList(L);
    // printf("\n");
    //开始插入e
    InsertLinkList(L,e);
    DisplayLinkList(L);
    return 0;
}
