//xdoj0221.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int c1=0,c2=0;
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            c1++;
        }else if(isdigit(s[i])){
            c2++;
        }
    }
    printf("%d,%d",c1,c2);
    return 0;
}