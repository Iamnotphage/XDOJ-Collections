//xodj0107.c
#include<stdio.h>
#include<stdlib.h>
//提前声明
typedef struct PosType{
    int x;
    int y;
}PosType;//坐标

typedef struct SNode{
    int step;//当前位置在路径上的序号
    PosType seat;//当前的坐标位置
    int d;//direction 往下一坐标的方向
    struct SNode* next;
}SNode,*Stack;

//全局变量
Stack S;//S始终指向栈顶,且带头结点
int Map[100][100];//0表示可以走，1表示障碍物，2表示曾经走过

void InitMap(int m,int n){
    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            if(i==0||j==0||i==m+1||j==n+1){
                Map[i][j]=1;//1表示障碍物
            }
        }
    }
}

//栈的相关操作
Stack InitStack(){
    Stack top=(Stack)malloc(sizeof(SNode));
    top->next=NULL;
    return top;
}

int StackEmpty(Stack top){
	if(top->next == NULL){
		return 1;
	}else{
		return 0;
	}
}

//向S压入节点pos
int Push(Stack top,SNode* pos){
	Stack node = (Stack)malloc(sizeof(SNode));
 
	if(node == NULL){
		return 0;
	}else{
		node->seat.x = pos->seat.x;
        node->seat.y = pos->seat.y;
        node->d = pos->d;

		node->next = top->next;
		top->next = node;
		return 1;
	}
}

//弹出S的顶部，并返回该结点
SNode* Pop(Stack top){
	Stack node;
	if(top->next == NULL){
		return NULL;
	}else{
		node = top->next;
		top->next = node->next;
		return node;
	}
}

//判断当前位置是否可以通过，是则返回1，否返回0，可通的定义是未曾走到过的通道块
int Pass(PosType pos){
    //可通且没走过，才算pass
    if(Map[pos.x][pos.y]==1){
        return 0;//1表示障碍物，不可通
    }
    if(Map[pos.x][pos.y]==2){
        return 0;//2表示走过的路径
    }
    return 1;
}

//留下足迹，即给Map赋值2，表示走过
void FootPrint(PosType pos){
    Map[pos.x][pos.y]=2;
    return;
}

//返回curpos当前位置的下一d方向的位置
PosType NextPos(PosType curpos,int d){
    //注意题目应该是东西方向是y，南北方向是x
    if(d==1){//东
        curpos.y++;
    }else if(d==2){
        //南
        curpos.x++;
    }else if(d==3){
        //西
        curpos.y--;
    }else if(d==4){
        //北
        curpos.x--;
    }
    return curpos;
}

//标记不能走的通路
void MarkPrint(PosType pos){
    Map[pos.x][pos.y]=1;
    return;
}

int MazePath(PosType start,PosType end){
    //设定当前位置为入口
    PosType curpos=start;
    int curstep=1;//探索第一步
    SNode* e;//e节点用于存储step，seat，d等信息
    do{
        if(Pass(curpos)){
            //如果当前位置可以通过
            FootPrint(curpos);//留下足迹
            //对e结点赋值
            e=(SNode*)malloc(sizeof(SNode));
            e->step=curstep;
            e->seat=curpos;
            e->d=1;

            Push(S,e);//加入路径
            if(curpos.x==end.x&&curpos.y==end.y){
                return 1;//找到出口
            }
            curpos=NextPos(curpos,1);//下一位置是当前位置的东
            curstep++;//探索下一步
        }else{
            //当前位置不可以通过
            if(!StackEmpty(S)){//栈非空
                e=Pop(S);
                while(e->d==4&&!StackEmpty(S)){
                    MarkPrint(e->seat);//留下不能通过的标记，并退回一步
                    e=Pop(S);
                }
                if(e->d<4){
                    e->d++;
                    Push(S,e);//换一个方向探索
                    curpos=NextPos(e->seat,e->d);//设定当前位置为新方向上的相邻块
                }
            }
        }
    }while(!StackEmpty(S));
    return 0;
}

int main(){
    //输入
    int m,n;
    PosType start;
    PosType end;
    S=InitStack();
    
    scanf("%d%d",&m,&n);
    InitMap(m,n);//初始化地图
    scanf("%d%d",&start.x,&start.y);
    scanf("%d%d",&end.x,&end.y);

    //输入迷宫
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&Map[i][j]);
        }
    }

    //1右 2下 3左 4上
    //这里开始解决迷宫
    if(MazePath(start,end)){
        //接下来输出栈S
        Stack res=InitStack();
        Stack top=S->next;
        while(top){
            Push(res,top);
            top=top->next;
        }
        top=res->next;
        while(top->next){
            printf("(%d,%d,%d),",top->seat.x,top->seat.y,top->d);
            top=top->next;
        }
        printf("(%d,%d,%d)",top->seat.x,top->seat.y,top->d);
        
    }else{
        printf("no");
        return 0;//没有通路输出no
    }
    return 0;
}