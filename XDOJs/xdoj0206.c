//xdoj0206.c
#include<stdio.h>
#include<string.h>
const int N=51;
int main(){
    char str[N];
    gets(str);
    char c;
    c=getchar();
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]!=c){
            printf("%c",str[i]);
        }
    }
    return 0;
}