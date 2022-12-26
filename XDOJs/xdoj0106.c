//xdoj0106.c
//废案，没考虑多重括号
#include<stdio.h>
int main(){
    int i=0,j=0,p=0;
    char MonsterWord[100];
    char TmpQueue[100];
    char ch;
    //input
    while(scanf("%c", &ch) && ch != '\n'){
        MonsterWord[i++] = ch;
    }
    MonsterWord[i]='\0';
    //假设没有左括号后紧接A或B
    while(p<i){
        if(MonsterWord[p]=='A'){
            printf("sae");
        }else if(MonsterWord[p]=='B'){
            printf("tsaedsae");
        }else if(MonsterWord[p]=='('){
            //左括号，开始进队列，队列第一个元素会穿插输出
            ++p;
            while(MonsterWord[p]!=')'){
                TmpQueue[j++]=MonsterWord[p];
                ++p;
            }
            //队列设置完毕，开始翻译
            j--;
            while(j>0){
                if(TmpQueue[j]=='A'){
                    printf("%csae",TmpQueue[0]);
                }else if(TmpQueue[j]=='B'){
                    printf("%ctsaedsae",TmpQueue[0]);
                }else{
                    //这是未压缩的翻译，穿插的输出
                    printf("%c%c",TmpQueue[0],TmpQueue[j]);
                }
                --j;
            }
            printf("%c",TmpQueue[0]);//补充最后一个
        }
        ++p;
    }
    return 0;
}