//xdoj0205.c
#include<stdio.h>
int main(){
    char a;
    int n;
    scanf("%c",&a);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=n-i;j>1;j--){
            printf(" ");
        }
        for(int k=0;k<=i;k++){
            printf("%c ",a);
        }
        printf("\n");
    }
    return 0;
}