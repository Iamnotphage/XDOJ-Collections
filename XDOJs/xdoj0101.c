//xdoj0101.c
#include<stdio.h>
int main(){
    char str[4];
    for(int i=0;i<4;i++){
        scanf("%c",&str[i]);
        if(str[i]>=65&&str[i]<=90){//大写转小写
            str[i]+=32;
        }else if(str[i]>=97&&str[i]<=122){//小写转大写
            str[i]-=32;
        }else if(str[i]>=48&&str[i]<=57){//48-57是数字,转为*
            str[i]='*';
        }else{
            str[i]='@';
        }
        printf("%c",str[i]);
    }
    return 0;
}