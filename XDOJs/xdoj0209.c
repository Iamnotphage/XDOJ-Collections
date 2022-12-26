//xdoj0209.c
#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    gets(str);
    int m;
    scanf("%d",&m);
    int len=strlen(str);
    for(int i=m+1;i<len;i++){
        printf("%c",str[i]);
    }
    return 0;
}