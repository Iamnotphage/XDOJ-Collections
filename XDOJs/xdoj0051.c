//xdoj0051.c
#include<stdio.h>
int main(){
    int a,b,c,d,min,t;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int num[4];
    num[0]=a;
    num[1]=b;
    num[2]=c;
    num[3]=d;
    //Selection Sort
    for(int i=0;i<3;i++){
        for(int j=i+1,min=i;j<4;j++){
            if(num[min]>num[j]){
                min=j;
            }
            if(min!=i){
                t=num[i];
                num[i]=num[min];
                num[min]=t;
            }
        }
    }
    printf("%d",num[3]);
    return 0;
}