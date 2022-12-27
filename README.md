# XDOJ-Collections🐹
Dedicated to collecting all XDOJs 
目前已收录239/???

# Brief-Introduction🐹
XDOJ is a online judge platform from Xidian University. 

There are some C/C++ problems.😁

This project aimes to collect all the XDOJs and share them for free.😊

# How to use🐹

Step1 Search for questions🤤

Step2 Download it😎

# Preview🐹
XDOJ0002.c for example.😍
```C
//xdoj0002.c
#include<stdio.h>
int main(){
    unsigned int n;
    unsigned int count=0;
    unsigned int a;
    scanf("%d",&n);
    int num[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        num[i]=a;
    }
    for(int j=0;j<n;j++){
        if(num[j]!=num[j+1]){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
```
