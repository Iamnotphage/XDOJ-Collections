//xdoj0046.c
#include<stdio.h>
void FindTurningPoint(int a[],int length){
    int count=0;
    for(int i=1;i<length-1;i++){//从第二个到倒数第二个
        if((a[i]>a[i+1]&&a[i]>a[i-1])||(a[i]<a[i+1]&&a[i]<a[i-1])){
            count++;
        }
    }
    printf("%d",count);
}
int main(){
    int n,count=0;
    scanf("%d",&n);
    int num[100];
    if(n>=3&&n<=100){
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        FindTurningPoint(num,n);
    }
    return 0;
}