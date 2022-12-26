//xdoj0250.c
#include<stdio.h>
int main(){
    int nums[100][100]={0},n,m,count=1,r=0,c=0;
    scanf("%d%d",&n,&m);
    int total=n*m;
    //四个边界 Right Left Up Down
    int Rlimit=m,Llimit=0,Ulimit=0,Dlimit=n;

    //理解为n次螺旋填数，每次填完，边界缩小
    while(count<=total){
        while(c<Rlimit){
            nums[r][c++]=count++;
        }c--;r++;

        while(r<Dlimit){
            nums[r++][c]=count++;
        }r--;c--;

        while(c>=Llimit){
            nums[r][c--]=count++;
        }c++;r--;

        while(r>Ulimit){
            nums[r--][c]=count++;
        }r++;c++;

        //每次螺旋之后，边界缩小
        Rlimit--;Llimit++;Ulimit++;Dlimit--;
    }

    //输出
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",nums[i][j]);
        }
        printf("\n");
    }

    return 0;
}