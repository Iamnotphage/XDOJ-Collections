//xdoj0294.cpp
#include<iostream>

using namespace std;

int arr[100];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    for(int i=0;i<n;i+=2){
        cout<<arr[i]<<" ";
    }
    for(int i=1;i<n;i+=2){
        cout<<arr[i]<<" ";
    }

    return 0;
}