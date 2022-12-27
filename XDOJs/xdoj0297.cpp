//xdoj0297.cpp
#include<iostream>
#include<cstring>
#define MAX_SIZE 90
using namespace std;

void MinT(char* str,int n){
    int flag;
    for(int i=1;i<=n;++i){
        //i必然要满足是长度n的公约数
        if(n%i==0){
            flag=1;//假设以i为周期满足条件
            for(int j=i;j<n;++j){
                if(str[j]!=str[j%i]){
                    flag=0;//以i为周期不满足条件
                    break;
                }
            }
            if(flag){
                cout<<i;
                break;
            }
        }
    }
}

int main(){
    char str[MAX_SIZE];
    cin>>str;
    int n=strlen(str);
    MinT(str,n);
    return 0;
}
