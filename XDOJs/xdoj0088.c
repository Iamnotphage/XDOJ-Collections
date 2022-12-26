//xdoj0088.c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char ISBN[14];
    int a=1;
    int sum=0;
    scanf("%13s",ISBN);
    int len=strlen(ISBN);
    for(int i=0;i<len-1;i++){
        if(isdigit(ISBN[i])){
            sum=sum+a*((int)ISBN[i]-48);
            a++;
        }
    }
    int check=sum%11;
    if((check!=10&&check==((int)ISBN[12]-48))||(check==10&&ISBN[12]=='X')){
        printf("Right");
    }else{
        for(int i=0;i<len-1;i++){
            printf("%c",ISBN[i]);
        }
        if(check==10){
            printf("X");
        }else{
            printf("%d",check);
        }
    }
    return 0;
}