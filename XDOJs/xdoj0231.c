//xdoj0231.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[101];
int main(){
    gets(str);
    char *p=str;
    int len=strlen(str),max=0,c=0;
    while(p<str+len){
        if(isalpha(*p)){
            c++;
        }else if(*p==' '|| *p=='.'){
            if(c>max){
                max=c;
            }
            c=0;
        }
        p++;
    }
    printf("%d",max);
    return 0;
}