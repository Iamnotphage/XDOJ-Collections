//xdoj0240.c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char out[100]={'\0'};
    int i=0;
    if(n>=0){
        while(n!=0){
            out[i++]=(n%10)+48;
            n/=10;
        }
        for(int j=i-1;j>=0;j--){
            printf("%c",out[j]);
        }
    }else{
        n=-1*n;
        while(n!=0){
            out[i++]=(n%10)+48;
            n/=10;
        }
        printf("-");
        for(int j=i-1;j>=0;j--){
            printf("%c",out[j]);
        }
    }
    
    return 0;
}