//xdoj0309.cpp
#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
typedef struct Node{
    int x,y,v;
}Node;
list<Node>B1;
list<Node>B2;
list<Node>B;

void MartixAdd(){
    //B用于存储结果 按照行小的先压入， 总体分为行相等，行1大，行2大
    list<Node>::iterator p1=B1.begin();
    list<Node>::iterator p2=B2.begin();

    while(p1!=B1.end() && p2!=B2.end()){
        //遍历俩个链表
        if(p1->x==p2->x){
            if(p1->y == p2->y){
                //坐标相同，实行相加
                if(p1->v + p2->v == 0){
                    //坐标相同，但是和为0，故无视
                    ;
                }else{
                    //和不为0，压入B
                    Node* s=(Node*)malloc(sizeof(Node));
                    s->x=p1->x;
                    s->y=p1->y;
                    s->v=p1->v+p2->v;
                    B.push_back(*s);
                }
                //坐标一样，俩迭代器都后移
                ++p1;
                ++p2;
            }else if(p1->y > p2->y){
                //列小的压入
                B.push_back(*p2);
                ++p2;
            }else if(p1->y < p2->y){
                B.push_back(*p1);
                ++p1;
            }
        }else if(p1->x > p2->x){
            //B1结点行比B2当前结点行 大，先入B2的结点
            B.push_back(*p2);
            ++p2;
        }else if(p1->x < p2->x){
            //入p1结点
            B.push_back(*p1);
            ++p1;
        }
    }//while
    //没完，可能有一个没遍历完
    if(p1==B1.end() && p2==B2.end()){
        //都遍历完，则返回
        return;
    }else{
        if(p1==B1.end()){
            while(p2!=B2.end()){
                B.push_back(*p2);
                ++p2;
            }
        }else if(p2==B2.end()){
            while(p1!=B1.end()){
                B.push_back(*p1);
                ++p1;
            }
        }
        return;
    }
}

int main(){
    int n,m,t;
    
    list<Node>::iterator p1;//p1迭代器遍历B1
    list<Node>::iterator p2;
    list<Node>::iterator p3;
    cin>>n>>m;

    //输入部分
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>t;
            if(t==1){
                Node* s=(Node*)malloc(sizeof(Node));
                s->x=i;
                s->y=j;

                B1.push_back(*s);
            }
        }
    }
    for(p1=B1.begin();p1!=B1.end();p1++){
        cin>>t;
        (*p1).v=t;
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>t;
            if(t==1){
                Node* s=(Node*)malloc(sizeof(Node));
                s->x=i;
                s->y=j;

                B2.push_back(*s);
            }
        }
    }
    for(p2=B2.begin();p2!=B2.end();p2++){
        cin>>t;
        (*p2).v=t;
    }

    //处理部分，相当于俩个链表x，y相同的运算，不同的合并，类似多项式加法
    MartixAdd();

    p3=B.begin();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(p3==B.end()){
                cout<<"0 ";
                continue;
            }else{
                if(i==p3->x&&j==p3->y){
                    cout<<"1 ";
                    ++p3;
                }else{
                    cout<<"0 ";
                }
            }
        }
        cout<<endl;
    }
    p3=B.begin();
    while(p3!=B.end()){
        cout<<p3->v<<' ';
        ++p3;
    }

    return 0;
}

