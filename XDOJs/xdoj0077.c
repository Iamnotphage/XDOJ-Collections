//xdoj0077.c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int flag=0,t=0;//flag表示下x和y的值计算完没有
    char op;
    char input[20];//8+8 +2+ 1+1
    int num[2]={0};//俩个元素分别是x y
    gets(input);
    for(int i=0;i<strlen(input);i++){//空格，数字，符号，三种情况
        if(isdigit(input[i])){//数字
            flag=1;
            num[t]=num[t]*10+(int)input[i]-48;
        }else if(input[i]==' '){//空格
            if(flag){
                t++;
            }
            flag=0;
            continue;
        }else{//符号
            op=input[i];
        }
    }
    switch(op){
        case '+':printf("%d",num[0]+num[1]);break;
        case '-':printf("%d",num[0]-num[1]);break;
        case '*':printf("%d",num[0]*num[1]);break;
        case '/':
            if(num[1]!=0){
                printf("%d",num[0]/num[1]);
                break;
            }
        case '%':
            if(num[1]!=0){
                printf("%d",num[0]%num[1]);
                break;
            }
        default:break;
    }
    return 0;
}