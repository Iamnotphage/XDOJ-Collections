//xdoj0258.c
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000 //address是非负5位整数

typedef struct LNode{
    int data;
    int next;
}LNode;

LNode Nodes[MAXSIZE];//结点数组，下标为address

void Display(LNode Nodes[],int p){
    while(p!=-1){
        if(Nodes[p].next==-1){
            printf("%05d %d -1",p,Nodes[p].data);
        }else{
            printf("%05d %d %05d\n",p,Nodes[p].data,Nodes[p].next);
        }
        p=Nodes[p].next;
    }
}

void DeleteNode(LNode Nodes[],int p,int address){
    //传入表和需要删除的结点地址
    while(Nodes[p].next != address){
        p=Nodes[p].next;
    }
    Nodes[p].next=Nodes[address].next;
}

int main(){
    int n,p,index;
    scanf("%d%d",&p,&n);

    for(int i=0;i<n;i++){
        scanf("%d",&index);//两个scanf必须分开，否则数组赋值会出错
        scanf("%d%d",&Nodes[index].data,&Nodes[index].next);
    }

    for(int i=p;i!=-1;i=Nodes[i].next){
        for(int j=Nodes[i].next;j!=-1;j=Nodes[j].next){
            if(Nodes[i].data == Nodes[j].data || Nodes[i].data == -Nodes[j].data){
                //abs相同，删除后一个结点
                DeleteNode(Nodes,p,j);
                n--;
            }
        }
    }
    printf("%d\n",n);
    Display(Nodes,p);
    return 0;
}
