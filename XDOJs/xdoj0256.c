//xdoj0256.c
#include<stdio.h>
#include<string.h>

void IsMatch(char* str,char* stack){
    int i=0,base=0,top=0;
    while(str[i]!='\0'){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            stack[top++]=str[i];
        }else if(str[i]==')'){
            if(stack[top-1]=='('){
                --top;
            }else{
                printf("Mismatch\n");
                return;//因为只用判断一次，可以直接返回0退出该函数
            }
        }else if(str[i]=='}'){
            if(stack[top-1]=='{'){
                --top;
            }else{
                printf("Mismatch\n");
                return;
            }
        }else if(str[i]==']'){
            if(stack[top-1]=='['){
                --top;
            }else{
                printf("Mismatch\n");
                return;
            }
        }
        ++i;
    }
    if(top==base){
        printf("Match\n");
    }else{
        printf("Mismatch\n");
    }
    return;
}

int main(){
    int i=0;
    char stack[128],str[100][128];
    while(1){
        scanf("%s",&str[i]);
        if(strcmp(str[i],"**0000**")==0){
            break;
        }
        IsMatch(str[i],stack);
    }
    return 0;
}