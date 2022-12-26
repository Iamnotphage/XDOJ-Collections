//xdoj0189.c
#include<stdio.h>
int main(){
    double s=100,h=50;
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        s+=2*h;
        h*=0.5;
    }
    printf("S=%.3lf h=%.3lf",s,h);
    return 0;
}