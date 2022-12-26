//xdoj0082.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int score=0;
    char password[50];
    gets(password);
    int len=strlen(password);
    int a[4]={0};
    int count=0;
    if(len==0){
        printf("%d",score);
    }else{
        score++;
        if(len>8){
            score++;
        }
        for(int i=0;i<len;i++){
            if(isupper(password[i])){
                a[0]=1;
            }else if(islower(password[i])){
                a[1]=1;
            }else if(isdigit(password[i])){
                a[2]=1;
            }else{
                a[3]=1;
            }
        }
        for(int i=0;i<4;i++){
            if(a[i]==1){
                count++;
            }
        }
        switch(count){
            case 2:score++;break;
            case 3:score+=2;break;
            case 4:score+=3;break;
            default:break;
        }
        printf("%d",score);
    }
    return 0;
}