//xdoj0265.cpp
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
