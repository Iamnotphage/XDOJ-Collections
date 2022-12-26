//xdoj0219.c
#include<stdio.h>
#include<math.h>
int main(){
    unsigned int n;
    int flag=1;
    scanf("%d",&n);
    if(n>=2){
        for(int i=2;i<=sqrt((double)n);i++){
            if(n%i==0){
                flag=0;
            }
        }
        if(flag){
            printf("YES");
        }else{
            printf("NO");
        }
    }
    return 0;
}