//xdoj0287.cpp
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
//min: 2 0 8 4
//max: 8 23 13 18
typedef struct Node{
    int i,j,value;
}Node;
int main(){
    int n,m,input[100][100],i=0,j=0,flag=0;//i,j操作，flag标记是否有马鞍点，默认没有
    vector<Node>min;
    vector<Node>max;
    Node* t=(Node*)malloc(sizeof(Node));//临时结点t，用于存贮三元组
    //输入部分 m是行，n是列，但是xdoj给的不清不楚，纯sb
    cin>>m>>n;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            cin>>input[i][j];
        }
    }
    //先按行查找每一行的最小值，把每一行的最小值入min
    for(i=0;i<m;++i){
        t->value=input[i][0];
        t->i=i+1;//在这里赋值，防止第一个就是最小值，导致ij未赋值
        for(j=1,t->j=j;j<n;++j){//t->j=j,不用加一，因为j赋值为1了
            if(t->value>input[i][j]){
                t->value=input[i][j];
                t->i=i+1;
                t->j=j+1;
            }
        }
        min.push_back(*t);
    }
    //再按列查找每一列的最大值，把每一列的最大值入max
    for(i=0;i<n;++i){
        t->value=input[0][i];
        t->j=i+1;//在这里赋值，防止第一个就是最大值，导致ij未赋值
        for(j=1,t->i=j;j<m;++j){
            if(t->value<input[j][i]){
                t->value=input[j][i];
                t->i=j+1;
                t->j=i+1;//注意这里反了一下
            }
        }
        max.push_back(*t);
    }
    //优先行来找马鞍点,也就是min先遍历,先遍历的在内层循环
    for(i=0;i<max.size();++i){//i操作max，j操作min
        for(j=0;j<min.size();++j){
            if(min.at(j).i==max.at(i).i && min.at(j).j==max.at(i).j && min.at(j).value==max.at(i).value){
                //结点相同，则符合马鞍点的定义
                cout<<min.at(j).i<<' '<<min.at(j).j<<' '<<min.at(j).value<<endl;
                flag=1;//输出过，说明有马鞍点
            }
        }
    }
    if(flag==0){
        cout<<"NO";
    }
    return 0;
}