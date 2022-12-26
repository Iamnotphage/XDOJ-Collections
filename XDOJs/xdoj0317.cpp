//xdoj0317.cpp
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int Node[100];//完全二叉树一定是先有左孩子的，要么满要么从左到右连续

void InitNode(){
    for(int i=0;i<100;++i){
        Node[i]=0;//0表示空
    }
}

int Pow(int x){//计算2的x次方
    return 1<<x;//左移x次，相当于2的x次方
}

//输出某一层的结点 如果有的话，一定是[2^(d-1)-1,2^d -1)这个范围 注意右边不取
void PrintLevel(int n,int d){
    //记得判定是否大于了树的深度
    if(d > (int)log2(n)+1){
        printf("EMPTY");
        return;
    }
    int start=Pow(d-1)-1;
    int end=Pow(d)-1;
    for(int i=start;i<end;++i){
        if(i==start && Node[i]==0){
            //开头就是空，说明这一层都是空
            printf("EMPTY");
            return;
        }
        if(Node[i]!=0){
            printf("%d ",Node[i]);
        }else{
            return;
        }
    }
    return;
}

int main(){
    int n,d;
    while(scanf("%d",&n) && n!=0){
        InitNode();
        for(int i=0;i<n;++i){
            scanf("%d",&Node[i]);
        }
        scanf("%d",&d);//depth
        PrintLevel(n,d);
        printf("\n");
    }
    return 0;
}