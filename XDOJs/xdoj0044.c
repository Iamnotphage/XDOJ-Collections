//xdoj0044.c
#include<stdio.h>
#include<math.h>
void judge(int n){
    int flag=1;
    for(int i=2;i<=sqrt((double)n);i++){
        if(n%i==0){
            flag=0;
        }
    }
    if(flag){
        printf("yes");
    }else{
        printf("%d",n);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int f1=1,f2=1,t;
    if(n==2){
        printf("%d",1);
    }else{
        //生成第n个fibonacci数
        for(int i=2;i<n;i++){
            t=f1+f2;
            f1=f2;
            f2=t;
        }
        n=f2;//此时n变为fibonacci数
        judge(n);
    }
    return 0;
}