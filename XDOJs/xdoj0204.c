//xdoj0204.c
//oj似乎有某种问题
#include<stdio.h>
#include<string.h>
const int N=101;
const int M=9;
int main(){
    char str[N]={'\0'},word[M]={'\0'},words[N][N];
    int count=0;
    gets(str);
    gets(word);
    int len=strlen(str),len1=strlen(word);
    if(len1>8){
        return 0;
    }
    int r=0,c=0;
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            words[r][c]='\0';
            r++;
            c=0;
        }else{
            words[r][c++]=str[i];
        }
    }
    for(int i=0;i<=r;i++){
        if(strcmp(word,words[i])==0){
            count++;
        }
    }
    printf("%s %d",word,count);
    return 0;
}