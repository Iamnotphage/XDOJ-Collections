//xdoj0052.c
#include<stdio.h>
int main(){
    char c=getchar();
    if(c>=97&&c<=122){//小a是97,z是122
        putchar(c-32);
    }else if(c>=65&&c<=90){//A 65 Z 90
        putchar(c+32);
    }else{
        putchar(c);
    }
    return 0;
}