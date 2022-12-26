//xdoj0296.cpp
#include<iostream>
using namespace std;
int main(){
    int n;
    char str[100];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str[i];
    }
    int i=0,j=n-1;
    while(i<n/2){
        if(str[i++]!=str[j--]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}