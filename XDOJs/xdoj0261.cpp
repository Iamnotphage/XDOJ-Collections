//xdoj0261.cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main(){//4 5 2 10 8
    int n,sum=0;
    int a[30];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;++i){
        a[i]=a[i-1]+a[i];
        sum+=a[i];
        sort(a+i-1,a+n);
    }
    cout<<sum;
    return 0;
}