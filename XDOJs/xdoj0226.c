//xdoj0226.c
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    gets(str);
    int len=strlen(str);
    int i,j,min,t;
    for(i=0;i<len-1;i++){
        for(j=i,min=i;j<len;j++){
            if(str[min]>str[j]){
                min=j;
            }
        }
        if(min!=i){
            int t=str[min];
            str[min]=str[i];
            str[i]=t;
        }
    }
    for(int i=0;i<len;i++){
        printf("%c",str[i]);
    }
    return 0;
}