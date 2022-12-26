//xdoj0038.c
#include<stdio.h>
#include<string.h>
int main(){
    char n[10000]={'\0'};//根本不需要10 0000 0000哈哈
    scanf("%s",&n);
    int len=strlen(n);
    int flag=1;
    for(int i=0;i<=len/2;i++){
        if(n[i]!=n[len-i-1]){
            flag=0;
        }
    }
    int sum=0;
    if(flag){
        for(int i=0;i<len;i++){
            sum+=(int)n[i]-48;
        }
        printf("%d",sum);
    }else{
        printf("no");
    }
    return 0;
}