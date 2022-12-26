//xdoj0084.c
#include<stdio.h>
#include<string.h>
void operation(char directory[],char op[]){
    int len=strlen(directory);
    int len2=strlen(op);
    int i,j=0;
    int t=len;
    if(strcmp(op,"cd /")==0){// cd /的命令
        if(len!=1){
            memset(directory,'\0',len);
            directory[0]='/';
        }
    }else if(strcmp(op,"cd ..")==0){// cd ..的命令
        if(len!=1){
            for(i=len-1;directory[i]!='/';i--){
                directory[i]='\0';
            }
        }
        if(strlen(directory)!=1&&directory[strlen(directory)-1]=='/'){
            directory[strlen(directory)-1]='\0';//删除后面的/
        }
    }else if(len2>=4&&op[3]=='/'){// cd /d1/d5这样的命令
        memset(directory,'\0',len);
        for(i=3;i<len2;i++){
            directory[j++]=op[i];
        }
    }else if(len2>=4&&op[3]!='.'){// cd d4/d5 这样的命令
        if(len!=1){
            directory[len]='/';
            len+=1;
            for(int i=3;i<len2;i++){
                directory[len++]=op[i];
            }
        }else{
            for(int i=3;i<len2;i++){
                directory[len++]=op[i];
            }
        }
        
    }
}
int main(){
    char directory[201]={'\0'};
    char op[201]={'\0'};
    gets(directory);
    int flag=1;
    while(flag){
        gets(op);
        if(strcmp(op,"pwd")==0){
            flag=0;
        }else{
            operation(directory,op);
        }
    }
    printf("%s",directory);
    return 0;
}