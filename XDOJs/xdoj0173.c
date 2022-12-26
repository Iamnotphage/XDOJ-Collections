//xdoj0173.c
#include<stdio.h>
//第n行第m个的序号是  (n-1)*5+m;
//那么对于数组的索引 则是 r*5+c+1;
void SearchSeats(int seats[20][5],int p){
    int r=0,c=0,count=0,flag=0;//flag表示 不得不拆开座位的情况
    if(p==5){//p是5的情况只有一类
        for(r=0;r<20;r++){
            if(seats[r][0]==0&&seats[r][1]==0&&seats[r][2]==0&&seats[r][3]==0&&seats[r][4]==0){
                for(int i=0;i<5;i++){
                    seats[r][i]=1;//表示已经有座位了
                }
                printf("%d %d %d %d %d\n",r*5+1,r*5+2,r*5+3,r*5+4,(r+1)*5);
                return;
            }
        }
        flag=1;//函数没有return，说明这是特殊情况
    }else{
        for(r=0;r<20;r++){
            count=0;
            for(c=0;c<5;c++){
                if(seats[r][c]==0){
                    count++;
                }else{
                    count=0;
                }
                if(count==p){
                    for(int i=c-p+1;i<=c;i++){
                        seats[r][i]=1;
                        printf("%d ",r*5+i+1);
                    }
                    printf("\n");
                    return;
                }
            }
        }
        flag=1;//函数没有return，不得不拆开座位
    }
    if(flag){//座位没有相邻的了
        count=0;
        for(r=0;r<20;r++){
            for(c=0;c<5;c++){
                if(seats[r][c]==0&&count!=p){
                    seats[r][c]=1;
                    printf("%d ",r*5+c+1);
                    count++;
                }
                if(count==p){
                    printf("\n");
                    return;
                }
            }
        }
    }
}
int main(){
    int count=0,seats[20][5]={0};//0表示座位是空
    int n,p[100],t,max=0;
    scanf("%d",&n);
    if(n>100||n<1){
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        max+=t;
        if(t<1||t>5){
            return 0;
        }
        p[i]=t;
    }
    if(max>100){
        return 0;
    }
    for(int i=0;i<n;i++){
        SearchSeats(seats,p[i]);
    }
    return 0;
}