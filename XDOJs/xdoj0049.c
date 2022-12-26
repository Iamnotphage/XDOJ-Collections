//xdoj0049.c
#include<stdio.h>
#include<math.h>
int main(){
    int a;
    scanf("%d",&a);
    if(sqrt((double)a)==(int)sqrt((double)a)){
        printf("%d",(int)sqrt((double)a));
    }else{
        printf("no");
    }
    return 0;
}