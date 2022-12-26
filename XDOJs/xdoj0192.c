//xdoj0192.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char input[20];
    gets(input);
    int len=strlen(input);
    for(int i=len-1;i>=0;i--){
        if(isdigit(input[i])){
            printf("%c",input[i]);
        }else if(input[i]==','){
            printf(" ");
        }
    }
    return 0;
}