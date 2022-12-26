//xdoj0314.cpp
#include<cstdio>
#include<cmath>
using namespace std;

void CountNodes(int m,int n){
    int delta=(int)log2(n)-(int)log2(m);
    int k=1<<delta;
    //俩个层数之差是k
    if(n>k*m+k-1){
        //说明n结点不在这个子树但是在同一层
        printf("%d\n",2*k-1);
    }else if(n<m*k){
        printf("%d\n",k-1);
    }else{
        //n和m都在同一个树
        printf("%d\n",k+n%k);
    }
    return;
}

int main(){
    int n,m;
    while(scanf("%d%d",&m,&n) && n+m!=0){
        CountNodes(m,n);
    }
    return 0;
}