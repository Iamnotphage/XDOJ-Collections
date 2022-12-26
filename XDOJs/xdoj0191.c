//xdoj0191.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char password[7];
    gets(password);
    for(int i=0;i<7;i++){
        if(isupper(password[i])){
            printf("%c",155-password[i]);
        }else if(islower(password[i])){
            printf("%c",219-password[i]);
        }else{
            printf("%c",password[i]);
        }
    }
    return 0;
}