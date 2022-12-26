//xdoj0302.c
#include<stdio.h>
#include<math.h>
int isPrimenum(int j){//判断j是不是素数
    int flag=1;
    for(int i=2;i<=sqrt((double)j);i++){//sqrt函数的参数要是实数
        if(j%i==0){
            flag=0;
            break;
        }
    }
    if(flag){
        return flag;
    }
    return 0;
}
void ProducePrimeNums(int prnums[],int p){
    int i=0;
    for(int j=2;i<p+10;j++){//判断j是不是素数
        if(isPrimenum(j)){
            prnums[i++]=j;
        }
    }
}
int main(){
    int prnums[150];//素数数组
    int p,sum=0;
    scanf("%d",&p);
    ProducePrimeNums(prnums,p);//找出p+10个素数,并存到数组里
    for(int i=p-1;i<p+10;i++){
        sum+=prnums[i];
    }
    printf("%d",sum);
    return 0;
}