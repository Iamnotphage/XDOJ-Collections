//xdoj0214.c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char string[101]={'\0'};
int num[5];
void count(int *num,char *string,int strlen){
    char *p=string;
    while(p<string+strlen){
        if(isupper(*p)){
            num[0]++;
        }else if(islower(*p)){
            num[1]++;
        }else if(*p==' '){
            num[2]++;
        }else if(isdigit(*p)){
            num[3]++;
        }else{
            num[4]++;
        }
        p++;
    }
    return;
}
int main(){
    gets(string);
    int len=strlen(string);
    count(num,string,len);
    for(int i=0;i<5;i++){
        printf("%d ",num[i]);
    }
    return 0;
}