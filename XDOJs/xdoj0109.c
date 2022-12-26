//xdoj0109.c
#include<stdio.h>
#include<string.h>
int main(){
    char c[101];
    char t[101]={'\0'};
    char b[101]={'\0'};
    int j=0,min,k,i;
    gets(c);
    int len=strlen(c);
    char f=c[0];
    for(int i=1;i<len;i++){
        if(c[i]>f){
            putchar(c[i]);
        }else if(c[i]<=f){
            t[j++]=c[i];
        }
    }
    int len1=strlen(t);
    putchar(f);
    //排序
    for(i=0;i<len1-1;i++){
        for(k=i+1,min=i;k<strlen(t);k++){
            if(t[k]<t[min]){
                min=k;
            }
        }
        if(min!=i){
            f=t[min];
            t[min]=t[i];
            t[i]=f;
        }
    }
    for(int i=0;i<len1;i++){
        printf("%c",t[i]);
    }
    return 0;
}