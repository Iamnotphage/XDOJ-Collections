//xdoj0233.c
#include<stdio.h>
#include<string.h>
char str[51]={'\0'};
char copy[51]={'\0'};
void copystr(char *str,int m,char *copy,int len){
    char *p=str+m-1;
    char *i=copy;
    while(p<str+len){
        *i = *p;
        p++;
        i++;
    }
    return;
}
int main(){
    gets(str);
    int m,len=strlen(str);
    scanf("%d",&m);
    if(m>len){
        printf("error");
        return 0;
    }
    copystr(str,m,copy,len);
    puts(copy);
    return 0;
}