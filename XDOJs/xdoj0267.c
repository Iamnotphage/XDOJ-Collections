//xdoj0267.c 废案
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct Stack{
    ElemType* base;
    ElemType* top;
    int stacksize;
}SqStack;

void InitStack(SqStack* s,int STACK_INIT_SIZE){
    s->base=(ElemType*)malloc( STACK_INIT_SIZE*sizeof(ElemType) );
    if(!s->base){
        printf("OVERFLOW");
        return;
    }
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
}

//返回s的栈顶元素 传入s结构体，该函数不需要改变s，所以直接传值
ElemType GetTop(SqStack s){
    if(s.base==s.top){
        printf("No Elem");
        return -1;//错误码
    }
    ElemType e= *(s.top -1);
    return e;
}

//压入元素e至栈顶，需要改变s，所以传地址
int Push(SqStack* s,ElemType e){
    if(s->top - s->base >= s->stacksize){
        //栈满，说明不行
        return 0;
    }
    
    *(s->top)=e;
    (s->top)++;
    return 1;
}

ElemType Pop(SqStack* s){
    if(s->top==s->base){
        return -1;
    }
    ElemType e= * --s->top;
    return e;
}

int PopSq[100][100];
int PushSq[100];

int main(){
    int M,N,K,p=0;//p用于指向Pushsq
    sacnf("%d%d%d",&M,&N,&K);
    SqStack S;//有长度限制的栈
    InitStack(&S,M);
    //输入第二行，入栈序列
    for(int i=0;i<N;i++){
        scanf("%d",&PushSq[i]);
    }
    //输入待判断的弹栈序列
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&PopSq[i][j]);
        }
    }
    //开始处理
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            for(int p=0;p<N;p++){
                
            }
            if(PopSq[i][j]==PushSq[p]){
                //相等的情况,直接入栈出栈
                if(Push(&S,PushSq[p])){
                    p++;
                    Pop(&S);
                }else{
                    printf("NO\n");
                    break;
                }
            }else{
                //不等,压入栈
                if(Push(&S,PushSq[p])){
                    p++;
                }else{
                    printf("NO\n");
                    break;
                }
            }
        }
        printf("YES\n");
    }
}