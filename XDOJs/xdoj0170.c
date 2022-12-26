//xdoj0170.c
#include<stdio.h>
struct info{
    char num[21];
    int total;
    int en;
};
void swap(struct info* a,struct info* b){
    struct info t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    struct info stus[200];
    for(int i=0;i<m;i++){
        scanf("%s %d %d",&stus[i].num,&stus[i].total,&stus[i].en);
    }
    int i,j,max;
    for(i=0;i<m-1;i++){
        for(j=i+1,max=i;j<m;j++){
            if(stus[j].total>stus[max].total){
                max=j;
            }else if(stus[j].total==stus[max].total){
                if(stus[j].en>stus[max].en){
                    max=j;
                }
            }
        }
        if(max!=i){
            swap(&stus[max],&stus[i]);
        }
    }
    for(i=0;i<n;i++){
        printf("%s %d %d\n",stus[i].num,stus[i].total,stus[i].en);
    }
    return 0;
}