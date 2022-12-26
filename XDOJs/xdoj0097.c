//xdoj0097.c
#include<stdio.h>
int main(){
    for(int i=97;i<=122;i++){
        printf("%c ",i);
    }
    printf("\n");
    for(int i=122;i>=97;i--){
        printf("%c ",i);
    }
    return 0;
}