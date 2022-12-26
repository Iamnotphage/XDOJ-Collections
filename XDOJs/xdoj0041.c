//xdoj0041.c
#include<stdio.h>
int main(){
    int n;
    int c1=0;
    int c2=0;
    int c3=0;
    int c4=0;
    int c5=0;
    int c6=0;
    int num[1000];
    double sum=0;
    int air[]={0,50,100,150,200,250,300};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    printf("%.2lf\n",sum/n);
    for(int i=0;i<n;i++){
        if(num[i]>=0&&num[i]<=50){
            c1++;
        }else if(num[i]>=51&&num[i]<=100){
            c2++;
        }else if(num[i]>=101&&num[i]<=150){
            c3++;
        }else if(num[i]>=151&&num[i]<=200){
            c4++;
        }else if(num[i]>=201&&num[i]<=300){
            c5++;
        }else if(num[i]>300){
            c6++;
        }
    }
    printf("%d %d %d %d %d %d",c1,c2,c3,c4,c5,c6);
    return 0;
}