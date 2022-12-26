//xdoj0169.c
#include<stdio.h>
struct info{
    int y;//year
    int m;//month
    int d;//day
    int s;//size
};
typedef struct info inf;
void swap(inf* a,inf* b){
    inf t=*a;
    *a=*b;
    *b=t;
}
int main(){
    
    struct info infos[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d/%d/%d    %d",&infos[i].y,&infos[i].m,&infos[i].d,&infos[i].s);
    }
    //sort
    int i,j,max;
    for(i=0;i<n-1;i++){
        for(j=i+1,max=i;j<n;j++){
            if(infos[j].y>infos[max].y){
                max=j;
            }else if(infos[j].y==infos[max].y){
                if(infos[j].m>infos[max].m){
                    max=j;
                }else if(infos[j].m==infos[max].m){
                    if(infos[j].d>infos[max].d){
                        max=j;
                    }else if(infos[j].d==infos[max].d){
                        if(infos[j].s>infos[max].s){
                            max=j;
                        }
                    }
                }
            }
        }
        if(max!=i){
            swap(&infos[i],&infos[max]);
        }
    }
    for(i=0;i<n;i++){
        printf("%d/%d/%d    %d\n",infos[i].y,infos[i].m,infos[i].d,infos[i].s);
    }
    return 0;
}
