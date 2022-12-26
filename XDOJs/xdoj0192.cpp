//xdoj0192.cpp
#include<cstdio>
using namespace std;
int main(){
    int input[5];
    scanf("%d,%d,%d,%d,%d",&input[0],&input[1],&input[2],&input[3],&input[4]);
    for(int i=4;i>=0;--i){
        printf("%d ",input[i]);
    }
    return 0;
}