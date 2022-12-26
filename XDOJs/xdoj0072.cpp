//xdoj0072.cpp
//xdoj0072.c
#include<stdio.h>
#include<string.h>
int main(){
    int max=0,t;
    char c[101];
    char ans[101];
    while(1){
        gets(c);
  		if(strcmp(c,"***end***")==0){
            break;
        }else{
            t=strlen(c);
  		    if(t>max){
                max=t;
                strcpy(ans,c);
  		    }
        }	
    }
    printf("%d\n%s",max,ans);
    return 0;
}