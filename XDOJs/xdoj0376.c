//xdoj0376.c
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
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
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}