//xdoj0080.c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char C,S[101];
    int n,count=0;
    scanf("%c%d",&C,&n);
    scanf("%100s",S);
    switch(n){
        case 0://大小写不敏感
            if(isupper(C)){
                C+=32;
            }
            for(int i=0;i<strlen(S);i++){
                if(isupper(S[i])){//大写转化成小写
                    S[i]+=32;
                }
                if(S[i]==C){
                    count++;
                }
            }
            printf("%d",count);    
            break;
        case 1:
            for(int i=0;i<strlen(S);i++){
                if(S[i]==C){
                    count++;
                }
            }
            printf("%d",count);    
            break;
        default:break;
    }
    return 0;
}