//xdoj0133.c
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode *List;
struct LNode{
    int c;//系数
    int exp;//指数
    List Next;
}p1,p2;//p1 p2两个链表

void Combine(List l,List s,int op){//多项式合并
    List p = l;//存个开头，用于下面合并的判断

    int flag=1;
    if(op==0){
        while(l&&s){
            //插在开头的情况，只用判断一次
            if(flag && l->exp > s->exp && p->Next==l){
                List temp=(List)malloc(sizeof(p1));
                temp->exp=s->exp;
                temp->c=s->c;

                temp->Next=l;
                p->Next=temp;

                s=s->Next;

                flag=0;
            }//最多只会执行一次

            if(s==NULL){
                return;
            }

            if(l->exp == s->exp){
                l->c = l->c + s->c;
                s=s->Next;
            }

            if(s==NULL){
                return;
            }

            if( (l->exp < s->exp && l->Next!=NULL && l->Next->exp > s->exp) || (l->exp < s->exp && l->Next==NULL)){
                //三种情况，一种是插在开头(已经处理)，一种是结尾，一种是中间
                List temp=(List)malloc(sizeof(p1));
                //数据域 存储到temp
                temp->exp=s->exp;
                temp->c=s->c;
                //插入
                temp->Next=l->Next;
                l->Next=temp;

                s=s->Next;
            }
            l = l->Next;
        }
    }else if(op==1){//复制op==1的情况，把其中一个加号改成减号
        while(l&&s){
            if(flag && l->exp > s->exp && p->Next==l){
                List temp=(List)malloc(sizeof(p1));
                temp->exp=s->exp;
                temp->c=-s->c;//这里改了

                temp->Next=l;
                p->Next=temp;

                s=s->Next;

                flag=0;
            }

            if(s==NULL){
                return;
            }

            if(l->exp == s->exp){
                l->c = l->c - s->c;//这里改了
                s=s->Next;
            }

            if(s==NULL){
                return;
            }

            if( (l->exp < s->exp && l->Next!=NULL && l->Next->exp > s->exp) || (l->exp < s->exp && l->Next==NULL)){
                List temp=(List)malloc(sizeof(p1));
                temp->exp=s->exp;
                temp->c=-s->c;//这里改了
                temp->Next=l->Next;
                l->Next=temp;
                s=s->Next;
            }
            l = l->Next;
        }
    }

}

void PrintList(List l,int* count){//输出多项式中某个项的函数  总体思路：在每个项的添加正负号
    if(l->c==0){
        return;
    }
    //指数 为0 和 为1 和 不为0也不为1 的情况 count用于判断是否打印过
    if(l->exp==0){
        if(l->c==1){
            if((*count)!=0){
                printf("+");
            }
            printf("1");
            (*count)=1;
        }else if(l->c==-1){
            printf("-1");
            (*count)=1;
        }else{
            if(l->c>0){
                if((*count)!=0){
                    printf("+");
                }
                printf("%d",l->c);
                (*count)=1;
            }else if(l->c<0){
                printf("%d",l->c);
                (*count)=1;
            }
            
        }
    }else if(l->exp==1){//指数为1
        if(l->c==1){
            if((*count)!=0){
                printf("+");
            }
            printf("x");
            (*count)=1;
        }else if(l->c==-1){
            printf("-x");
            (*count)=1;
        }else{
            if(l->c>0){
                if((*count)!=0){
                    printf("+");
                }
                printf("%dx",l->c);
                (*count)=1;
            }else{
                printf("%dx",l->c);
                (*count)=1;
            }
        }
    }else{//指数不为0也不为1
        if(l->c==1){
            if((*count)!=0){
                printf("+");
            }
            printf("x^%d",l->exp);
            (*count)=1;
        }else if(l->c==-1){
            printf("-x^%d",l->exp);
            (*count)=1;
        }else{
            if(l->c>0){
                if((*count)!=0){
                    printf("+");
                }
                printf("%dx^%d",l->c,l->exp);
                (*count)=1;
            }else{
                printf("%dx^%d",l->c,l->exp);
                (*count)=1;
            }
        }
    }
    return;
}
int main(){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);

    //存储第一个多项式
    List Ptrl1=(List)malloc(sizeof(p1));//创建并分配头结点的内存
    Ptrl1->Next=NULL;//指针域设为空
    List s,p;
    p=Ptrl1;
    //这里采用尾插法
    for(int i=0;i<n;i++){
        s=(List)malloc(sizeof(p1));
        scanf("%d%d",&s->c,&s->exp);
        p->Next=s;
        s->Next=NULL;
        p=s;
    }
    
    //重复上面的操作，存储第二个多项式
    List Ptrl2=(List)malloc(sizeof(p2));
    Ptrl2->Next=NULL;
    p=Ptrl2;
    for(int i=0;i<m;i++){
        s=(List)malloc(sizeof(p2));
        scanf("%d%d",&s->c,&s->exp);
        p->Next=s;
        s->Next=NULL;
        p=s;
    }
    //让Ptrl1 是 较长的多项式的头  Ptrl2是较短多项式的头
    if(n<m){
        s=Ptrl1;
        Ptrl1=Ptrl2;
        Ptrl2=s;
    }
    //先合并多项式
    Combine(Ptrl1,Ptrl2,t);
    //输出部分
    List out=Ptrl1->Next;

    //判断是否全部为0
    int sign=0;//假设全为0
    while(out){
        if(out->c!=0){
            sign=1;
            break;
        }
        out=out->Next;
    }

    if(sign==0){
        printf("0");//全为0说明多项式完全抵消了
        return 0;
    }

    out=Ptrl1->Next;
    int count=0;//防止开头出现加号
    while(out&&sign){
        PrintList(out,&count);
        out=out->Next;
    }
    return 0;
}