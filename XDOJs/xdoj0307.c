//xdoj0307.c
#include<stdio.h>

int main(){
    int top=0,base=0,i=0;
    char str[100],stack[100],ch;
    //傻逼oj不能用gets
    while(scanf("%c", &ch) && ch != '\n'){
        str[i++] = ch;
    }
    str[i] = '\0';
    i=0;
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            stack[top++]=str[i];
        }else if(str[i]==')'){
            if(stack[top-1]=='('){
                --top;
            }else{
                printf("wrong");
                return 0;//因为只用判断一次，可以直接返回0退出主程序
            }
        }else if(str[i]=='}'){
            if(stack[top-1]=='{'){
                --top;
            }else{
                printf("wrong");
                return 0;
            }
        }else if(str[i]==']'){
            if(stack[top-1]=='['){
                --top;
            }else{
                printf("wrong");
                return 0;
            }
        }
        ++i;
    }
    if(top==base){
        printf("right");
    }else{
        printf("wrong");
    }
    return 0;
}