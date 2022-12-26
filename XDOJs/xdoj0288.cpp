//xdoj0288.cpp
#include<iostream>
using namespace std;
//注意下面这个next函数是根据一般的情况来的，也就是从1数起，第一二个固定是0，1
//题目是从0数，第一二个固定是-1，0，只要最后输出减一就行了
void Next(char* T,int* next,int Tlength){
    next[1]=0;
    next[2]=1;
    int i=2;
    int j=1;
    while(i<Tlength){
        if(j==0||T[i-1]==T[j-1]){
            ++i;
            ++j;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

int main(){
    int n,next[100];
    char T[100];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>T[i];
    }
    Next(T,next,n);
    for(int i=1;i<=n;++i){
        cout<<next[i]-1<<' ';
    }
    return 0;
}