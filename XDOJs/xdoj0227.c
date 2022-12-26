//xdoj0227.c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int count=0;
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}