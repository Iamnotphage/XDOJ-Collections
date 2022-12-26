#include<stdio.h>
#include<stdlib.h>
 
//单链表结构体 
typedef struct queue{
	int num;
	struct queue *next;
}QNode, *Queue; 
 
//用头插法创建编号链表从1到N 
void Create(Queue *q, int N){
	Queue node;
	int i;
	*q = (Queue)malloc(sizeof(QNode));
	(*q)->next = NULL;
	for(i=N; i>0; i--){
		node = (Queue)malloc(sizeof(QNode));
		node->num = i;
		node->next = (*q)->next;
		(*q)->next = node;
	}
}
 
//报数出队列 
void Out(Queue *q, int N){
	int i;
	int count = N;	//记录队列个数 
	Queue p,t;
	//当个数不超过3时结束循环
	while( N>3 ){
		//报到2的倍数的人出列 
		p = (*q)->next;
		t = (*q);
		N = count;
		for(i=1; i<=N; i++){
			if(i%2 == 0){
				t->next = p->next;
				p = p->next;
				count--;
			}else{
				p = p->next;
				t = t->next;
			} 
		} 
		if(count<=3)	//注意是一轮结束在判断，不能在出的时候就判断 
			return;
		//报到3的倍数的人出列 
		p = (*q)->next;
		t = (*q);
		N = count;
		for(i=1; i<=N; i++){
			if(i%3 == 0){
				t->next = p->next;
				p = p->next;
				count--;
			}else{
				p = p->next;
				t = t->next;
			} 
		} 
		if(count<=3)
			return;
	}
 
}
 
//输出函数 
void Print(Queue head){
	Queue p;
	p = head->next;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
}
 
int main(){
	Queue q;
	int N;
	scanf("%d", &N);
	Create(&q, N);
	Out(&q, N);
	Print(q);
	return 0;
} 