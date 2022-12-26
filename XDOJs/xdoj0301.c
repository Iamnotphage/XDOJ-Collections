//xdoj0301.c
#include<stdio.h>
void Sum(int a,int anum[]){
    int count=1;
    int sum=1;
    for(int i=2;i<=a/2;i++){
        if(a%i==0){
            sum+=i;
            count++;
        }
    }
    anum[0]=sum;
    anum[1]=count;
}
int main(){
    int a,b;
    int anum[2];
    int bnum[2];
    scanf("%d%d",&a,&b);
    Sum(a,anum);
    Sum(b,bnum);
    if(a==bnum[0]&&b==anum[0]){
        printf("yes %d %d",anum[1],bnum[1]);
    }else{
        printf("no %d %d",anum[1],bnum[1]);
    }
    return 0;
}