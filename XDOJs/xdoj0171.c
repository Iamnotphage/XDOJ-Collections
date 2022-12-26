//xdoj0171.c
#include<stdio.h>
struct info{
    int k;
    int total;
};
int get_time(int h1,int h2,int m1,int m2){
    return ((h2-h1)*60+m2-m1);
}
void swap(struct info* a,struct info* b){
    struct info t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n;
    scanf("%d",&n);
    struct info infos[105]={0};
    int len=0,t1,t2,t3,t4,t5;
    for(int i=0;i<n;i++){
        scanf("%d %d:%d %d:%d",&t1,&t2,&t3,&t4,&t5);
        if(len<t1){
            len=t1;
        }
        infos[t1].k=t1;
        infos[t1].total += get_time(t2,t4,t3,t5);
    }
    int i,j,max;
    for(i=1;i<=len-1;i++){
        if(infos[i].k==0){
            continue;
        }
        for(j=i+1,max=i;j<=len;j++){
            if(infos[j].k!=0){
                if(infos[j].total>infos[max].total){
                    max=j;
                }else if(infos[j].total==infos[max].total){
                    if(infos[j].k<infos[max].k){
                        max=j;
                    }
                }
            }
        }
        if(max!=i){
            swap(&infos[max],&infos[i]);
        }
    }
    for(i=1;i<=len;i++){
        if(infos[i].k){
            printf("%d %d\n",infos[i].k,infos[i].total);
        }
    }
    return 0;
}