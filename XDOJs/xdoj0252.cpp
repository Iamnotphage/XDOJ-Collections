//xdoj0252.cpp
#include<iostream>
#include<algorithm>
#define MAX_SIZE 110
using namespace std;

int main(){
    int n,arr[MAX_SIZE];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}