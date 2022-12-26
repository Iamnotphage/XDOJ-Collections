//xdoj0278.c
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int num,passwopd;
    struct LNode *next;
}LNode,*Linklist;

Linklist L,p,s;
//创建循环链表
void Creatlinklist(int n){
    L = (Linklist)malloc(sizeof(LNode));
	p = L;
    int i;
    int x;
    for (i = 1; i < n;i++){
        s = (Linklist)malloc(sizeof(LNode));
        p->next = s;
        p = s;
    }
    p->next = L;
    s = L;
}
void Input(int n){
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s->passwopd = x;
		s->num = i;
		s=s->next;
	}
	s = p;
}
//输出并出列
void Output(int n,int m){
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <m;j++){
            s = s->next;
        }
        p = s->next;
        m = p->passwopd;
        printf("%d ", p->num);
        s->next = p->next;
        free(p);
    }
}
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    Creatlinklist(n);
    Input(n);
    Output(n, m);
    return 0;
}