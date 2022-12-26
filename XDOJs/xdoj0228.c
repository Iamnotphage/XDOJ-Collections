//xdoj0228.c
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i+=2){
        printf("%c",s[i]);
    }
    return 0;
}