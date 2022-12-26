//xdoj0246.c   0204
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[101]={'\0'},word[9]={'\0'},words[101][101];
    int count=0;
    gets(str);
    gets(word);
    int len=strlen(str),len1=strlen(word);
    if(len1>8){
        return 0;
    }
    for(int i=0;i<len;i++){
        if(isupper(str[i])){
            str[i]+=32;
        }
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