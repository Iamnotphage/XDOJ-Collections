//xdoj0193.c
#include<stdio.h>
int main(){
    int n,a,min=100,max=0,sum=0;
    scanf("%d",&n);
    if(n>=3&&n<=10){
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a<min){
                min=a;
            }
            if(a>max){
                max=a;
            }
            sum+=a;
        }
        sum=sum-max-min;
        double avg=(double)sum/(n-2);
        printf("%.2lf",avg);
    }
    return 0;
}