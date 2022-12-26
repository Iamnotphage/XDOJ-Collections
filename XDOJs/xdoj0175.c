//xdoj0175.c
#include<stdio.h>
struct Windows{
    int x1;
    int x2;
    int y1;
    int y2;
    int id;//编号
};

struct Clicks{
    int x;
    int y;
};

struct Windows wins[10];
struct Clicks click[50];
int flag=0;

void ToTop(struct Windows wins[10],struct Windows t,int index){
    //将窗口t放置在最顶部
    if(index==0){
        return;
    }else{
        struct Windows temp=t;
        for(int i=index;i>=1;i--){
            wins[i]=wins[i-1];
        }
        wins[0]=t;
        return;
    }
}

int Judge(struct Windows win,struct Clicks click){
    if(click.x>=win.x1&&click.x<=win.x2&&click.y>=win.y1&&click.y<=win.y2){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    int v=1;//表示原来的编号
    for(int i=N-1;i>=0;i--){
        scanf("%d%d%d%d",&wins[i].x1,&wins[i].y1,&wins[i].x2,&wins[i].y2);
        wins[i].id=v++;
    }
    for(int i=0;i<M;i++){
        scanf("%d%d",&click[i].x,&click[i].y);
    }
    for(int i=0;i<M;i++){
        flag=0;
        for(int j=0;j<N;j++){
            if(Judge(wins[j],click[i])){
                printf("%d\n",wins[j].id);
                ToTop(wins,wins[j],j);
                flag=1;
                break;//点击成功，跳出wins的遍历
            }else{
                continue;
            }
        }
        if(flag==0){
            printf("IGNORED\n");
        }
    }
    return 0;
}