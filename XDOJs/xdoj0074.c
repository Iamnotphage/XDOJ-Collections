//xdoj0074.c
#include<stdio.h>
#include<string.h>
//分析：如果合法的话所有括号（除去其他符号）都应该是相邻对称的
//遇到左括号就存储（push）到stack，遇到右括号就判断是否与stack的最后一项匹配
//如果匹配，stack的最后一项就要删除（pop），如果不匹配，flag标签改变（no）
int main(){
    char input[51];
    char stack[51];
    int flag=0,j=0;//j是栈（stack）的索引,flag是0表示正确
    gets(input);
    for(int i=0;i<strlen(input);i++){
        if(input[i]=='('||input[i]=='['||input[i]=='{'){
            stack[j++]=input[i];//push进栈了j个左括号
        }
        switch(input[i]){//右括号的三种情况
            case ')':
                if(stack[j-1]=='('){//第14行已经j++了，j-1才是stack的最后一项
                    j--;//j-- 表示之前的j已经匹配上了右括号，这样遇到下一个左括号可以赋值来同时完成pop和push
                    break;
                }else{
                    flag=1;
                }
                break;
            case ']':
                if(stack[j-1]=='['){
                    j--;
                    break;
                }else{
                    flag=1;
                }
                break;
            case '}':
                if(stack[j-1]=='{'){
                    j--;
                    break;
                }else{
                    flag=1;
                }
                break;
        }
    }
    if(flag==0&&j==0){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}