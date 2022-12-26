//xdoj0276.c
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int p;//系数
    int e;//指数
    struct LNode* next;
}LNode,*LinkList;

LinkList InitLinkList(){
    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    return L;
}

//多项式相加
LinkList PolyAdd(LinkList L1,LinkList L2){
    LinkList p1=L1->next;
    LinkList p2=L2->next;
    LinkList result=(LinkList)malloc(sizeof(LNode));//作为结果返回
    result->next=NULL;
    result->e=0;//头结点存多项式的项数，便于输出 result->e表示结果的项数
    LinkList p3=result;
    //指数一样，则系数相加，若系数之和为0，则free
    //指数不一样，指数大的先插入进去,每执行一次插入，记录一次
    while(p1!=NULL && p2!=NULL){//注意这里最后要检验 究竟是谁先到底
        if(p1->e > p2->e){
            //p1的指数比较大，插入p1结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p1->e;
            s->p=p1->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p1=p1->next;

        }else if(p1->e < p2->e){
            //p2的指数比较大，插入p2结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p2->e;
            s->p=p2->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p2=p2->next;


        }else{//指数相等
            if(p1->p + p2->p == 0){
                ;
            }else{
                //系数之和不为0
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=p1->p + p2->p;
                s->e=p1->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;
            }
            //指数相等的情况，p1 和 p2 都要移动
            p1=p1->next;
            p2=p2->next;
        }
    }
    //还没完，while条件内部 不一定遍历结束
    if(p1 == NULL && p2==NULL){
        //如果p1和p2 都空，则恰好遍历结束
        return result;
    }else{
        if(p1==NULL){
            while(p2){
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=p2->p;
                s->e=p2->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;

                p2=p2->next;
            }
        }else if(p2==NULL){
            while(p1){
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=p1->p;
                s->e=p1->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;

                p1=p1->next;
            }
        }
        return result;
    }
}

//多项式相减 注意插入的时候先把L2的结点系数乘-1
LinkList PolyMinus(LinkList L1,LinkList L2){
    LinkList p1=L1->next;
    LinkList p2=L2->next;
    LinkList result=(LinkList)malloc(sizeof(LNode));//作为结果返回
    result->next=NULL;
    result->e=0;//头结点存多项式的项数，便于输出 result->e表示结果的项数
    LinkList p3=result;
    //指数一样，则系数相加，若系数之差为0，则free
    //指数不一样，指数大的先插入进去,每执行一次插入，记录一次
    while(p1!=NULL && p2!=NULL){//注意这里最后要检验 究竟是谁先到底
        if(p1->e > p2->e){
            //p1的指数比较大，插入p1结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p1->e;
            s->p=p1->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p1=p1->next;

        }else if(p1->e < p2->e){
            //p2的指数比较大，插入p2结点 记得乘-1
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p2->e;
            s->p=-(p2->p);
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p2=p2->next;

        }else{//指数相等
            if(p1->p - p2->p == 0){
                ;
            }else{
                //系数之差不为0
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=p1->p - p2->p;
                s->e=p1->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;
            }
            //指数相等的情况，p1 和 p2 都要移动
            p1=p1->next;
            p2=p2->next;
        }
    }
    //还没完，while条件内部 不一定遍历结束
    if(p1 == NULL && p2==NULL){
        //如果p1和p2 都空，则恰好遍历结束
        return result;
    }else{
        if(p1==NULL){
            while(p2){//注意p2的系数要取相反数
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=-(p2->p);
                s->e=p2->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;

                p2=p2->next;
            }
        }else if(p2==NULL){
            while(p1){
                LinkList s=(LinkList)malloc(sizeof(LNode));
                s->p=p1->p;
                s->e=p1->e;
                s->next=NULL;

                p3->next=s;
                p3=p3->next;

                result->e++;

                p1=p1->next;
            }
        }
        return result;
    }
}

void DisplayLinkList(LinkList L){
    LinkList p=L;
    printf("%d",p->e);
    p=p->next;
    if(p==NULL){//但如果多项式没有非零系数项，则仅用0（M的值）表示，后面没有系数和幂次值出现。
        //沙比oj有测试样例结果为0的
        //细节问题
        return;
    }
    printf(" ");
    while(p->next){
        printf("%d %d ",p->p,p->e);
        p=p->next;
    }
    printf("%d %d",p->p,p->e);
    return;
}

int main(){
    int m1,m2;
    LinkList L1=InitLinkList();
    LinkList L2=InitLinkList();
    LinkList p1=L1;
    LinkList p2=L2;

    //输入部分
    scanf("%d",&m1);
    for(int i=0;i<m1;++i){
        LinkList s=(LinkList)malloc(sizeof(LNode));
        scanf("%d %d",&s->p,&s->e);
        s->next=NULL;
        p1->next=s;

        p1=p1->next;
    }

    scanf("%d",&m2);
    for(int i=0;i<m2;++i){
        LinkList s=(LinkList)malloc(sizeof(LNode));
        scanf("%d %d",&s->p,&s->e);
        s->next=NULL;
        p2->next=s;

        p2=p2->next;
    }

    //开始处理
    LinkList p3=PolyAdd(L1,L2);
    printf("\n");
    DisplayLinkList(p3);

    printf("\n");
    LinkList p4=PolyMinus(L1,L2);
    DisplayLinkList(p4);

    return 0;
}