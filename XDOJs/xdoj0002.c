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