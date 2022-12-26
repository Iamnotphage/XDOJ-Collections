//xdoj0268.c
#include<stdio.h>

int main(){
    int n,top=0,base=0,i=0,j=0,flag=1;
    char str[100][100],stack[100];
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        scanf("%s",&str[k]);
    }
    while(j<n){
        while(str[j][i]!='\0'){
            if(str[j][i]=='('||str[j][i]=='{'||str[j][i]=='['){
                stack[top++]=str[j][i];
            }else if(str[j][i]==')'){
                if(stack[top-1]=='('){
                    --top;
                }else{
                    printf("No\n");
                    flag=0;
                    break;
                }
            }else if(str[j][i]=='}'){
                if(stack[top-1]=='{'){
                    --top;
                }else{
                    printf("No\n");
                    flag=0;
                    break;
                }
            }else if(str[j][i]==']'){
                if(stack[top-1]=='['){
                    --top;
                }else{
                    printf("No\n");
                    flag=0;
                    break;
                }
            }
            ++i;
        }
        if(flag){
            if(top==base){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
        
        ++j;
        top=0;
        i=0;
        flag=1;
    }
    return 0;
}