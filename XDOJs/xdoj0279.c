//xdoj0279.c
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

//多项式相加 指数递增
LinkList PolyAdd(LinkList L1,LinkList L2){
    LinkList p1=L1->next;
    LinkList p2=L2->next;
    LinkList result=(LinkList)malloc(sizeof(LNode));//作为结果返回
    result->next=NULL;
    result->e=0;//头结点存多项式的项数，便于输出 result->e表示结果的项数
    LinkList p3=result;
    //指数一样，则系数相加，若系数之和为0，则free
    //指数不一样，指数小的先插入进去,每执行一次插入，记录一次
    while(p1!=NULL && p2!=NULL){//注意这里最后要检验 究竟是谁先到底
        if(p1->e > p2->e){
            //p1的指数比较大，插入p2结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p2->e;
            s->p=p2->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p2=p2->next;

        }else if(p1->e < p2->e){
            //p2的指数比较大，插入p1结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p1->e;
            s->p=p1->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p1=p1->next;


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
    //指数一样，则系数相减，若系数之差为0，则free
    //指数不一样，指数大的先插入进去,每执行一次插入，记录一次
    while(p1!=NULL && p2!=NULL){//注意这里最后要检验 究竟是谁先到底
        if(p1->e > p2->e){
            //p1的指数比较大，插入p2结点 记得乘-1
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p2->e;
            s->p=-(p2->p);
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p2=p2->next;

        }else if(p1->e < p2->e){
            //p2的指数比较大，插入p1结点
            LinkList s=(LinkList)malloc(sizeof(LNode));
            s->e=p1->e;
            s->p=p1->p;
            s->next=NULL;

            p3->next=s;
            p3=p3->next;

            result->e++;

            p1=p1->next;

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

//输出L表，以多项式形式输出
void DisplayLinkList(LinkList L){
    LinkList p=L->next;
    if(p==NULL){
        //p为空，则说明L1和L2运算后为0
        printf("0");
        return;
    }
    while(p){
        if(p->p < 0){
            //如果系数小于0
            if(p->p == -1){
                //如果系数是-1，输出的时候应该是-x的某次方，而不是-1x的某次方
                if(p->e==1){
                    //如果系数是-1，且指数是1，那么应该输出-x
                    printf("-x");
                }else if(p->e==0){
                    //如果系数是-1，且指数是0，那么应该输出-1
                    printf("-1");
                }else{
                    //如果系数是-1，且指数不是0和1，那么应该输出-x的某次方
                    printf("-x^%d",p->e);
                }
            }else if(p->p!=-1){
                //如果系数不是-1，那么输出应该是px的某次方
                if(p->e==1){
                    //如果系数不是-1，且指数是1，那么应该输出px
                    printf("%dx",p->p);
                }else if(p->e==0){
                    //如果系数不是-1，且指数是0，那么应该输出p
                    printf("%d",p->p);
                }else{
                    //如果系数不是-1，且指数不是0和1，那么应该输出px的某次方
                    printf("%dx^%d",p->p,p->e);
                }
            }
        }else{
            //如果系数大于0
            if(p->p == 1){
                //如果系数是1，输出的时候应该是x的某次方
                if(p->e==1){
                    printf("x");
                }else if(p->e==0){
                    printf("1");
                }else{
                    printf("x^%d",p->e);
                }
            }else{
                //如果系数不是1，那么输出应该是px的某次方
                if(p->e==1){
                    //如果系数不是1，且指数是1，那么应该输出px
                    printf("%dx",p->p);
                }else if(p->e==0){
                    //如果系数不是1，且指数是0，那么应该输出p
                    printf("%d",p->p);
                }else{
                    //如果系数不是1，且指数不是0和1，那么应该输出px的某次方
                    printf("%dx^%d",p->p,p->e);
                }
            }
        }
        if(p->next!=NULL){//如果p的下一个存在
            if(p->next->p > 0 ){//且下一个系数大于0
                //则由此补上加号
                printf("+");
            }
        }
        p=p->next;
    }
}

int main(){
    int n,m,t;
    LinkList L1=InitLinkList();
    LinkList L2=InitLinkList();
    LinkList p1=L1;
    LinkList p2=L2;

    //input part
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++){
        LinkList s=(LinkList)malloc(sizeof(LNode));
        scanf("%d%d",&s->p,&s->e);
        p1->next=s;
        s->next=NULL;

        p1=p1->next;
    }
    for(int i=0;i<m;i++){
        LinkList s=(LinkList)malloc(sizeof(LNode));
        scanf("%d%d",&s->p,&s->e);
        p2->next=s;
        s->next=NULL;

        p2=p2->next;
    }
    //operation part
    LinkList L3;
    switch(t){
        case 0:L3=PolyAdd(L1,L2);break;
        case 1:L3=PolyMinus(L1,L2);break;
        default:break;
    }
    //outputpart
    DisplayLinkList(L3);

    return 0;
}