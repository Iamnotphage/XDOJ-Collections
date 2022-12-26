//xdoj0243.c
#include<stdio.h>
int main(){
    typedef struct stu{
        char name[20];
        int s[5];
        int plus;
        int sum; 
    }STU;
    int n;
    scanf("%d",&n);
    STU info[100];
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d %d %d %d",&info[i].name,&info[i].s[0],&info[i].s[1],&info[i].s[2],&info[i].s[3],&info[i].s[4],&info[i].plus);
        info[i].sum=info[i].s[0]+info[i].s[1]+info[i].s[2]+info[i].s[3]+info[i].s[4]+info[i].plus;
    }
    int i,j,max;
    STU t;
    for(i=0;i<n-1;i++){
        for(j=i,max=i;j<n;j++){
            if(info[max].sum<info[j].sum){
                max=j;
            }else if(info[max].sum==info[j].sum){
                max=info[max].plus>info[j].plus?max:j;
            }
        }
        if(max!=i){
            t=info[max];
            info[max]=info[i];
            info[i]=t;
        }
    }
    for(int i=0;i<n;i++){
        printf("%s %d %d\n",info[i].name,info[i].sum,info[i].plus);
    }
}