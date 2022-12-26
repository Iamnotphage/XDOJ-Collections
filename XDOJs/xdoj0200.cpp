//xdoj0200.cpp
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<9-n;++i){
        printf("%d ",i+n+2);
    }
    for(int i=0;i<n+1;++i){
        printf("%d ",i+1);
    }
    return 0;
}