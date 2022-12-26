//xdoj0043.c
#include <stdio.h>
int main(){
    long a;
    int c=0,max=0,min=9;
    scanf("%ld",&a);
    do{
        int t = a%10;
        if(t>max)max=t;
        if(t<min)min=t;
        a/=10;
        c++;
    }while(a>0);
    printf("%d %d %d",c,max,min);
    return 0;
}