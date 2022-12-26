//xdoj0316.cpp
#include<cstdio>
using namespace std;
//观察易得左右子树除2就是根结点的值
int main(){
    int n,m;//沙比题目也不说清楚00是什么，纯属挠谈
    while(scanf("%d%d",&n,&m) && n+m!=0){
        while(n!=m){
            n>m?n/=2:m/=2;
        }
        printf("%d\n",n);
    }
    return 0;
}