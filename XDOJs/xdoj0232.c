//xdoj0232.c 一样
//xdoj0376.c
#include<stdio.h>
#include<string.h>
char str[100];
int main(){
    gets(str);
    int len=strlen(str);
    char *l=str;
    char *r=str+len-1;
    int flag=1;
    while(l<=r){
        if(*l != *r){
            flag=0;
            break;
        }
        l++;
        r--;
    }
    if(flag){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}