//xdoj0005.c
#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int nums[30][30]={0};
    int rowsame[30][30]={0};//第0列是nums第一行中连续三个相同的列标
    int columnsame[30][30]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    //按行查找相同,rowsame的每一列存着nums每一行相同的数的列标
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(nums[i][j]==nums[i][j+1]&&nums[i][j]==nums[i][j+2]){
                rowsame[j][i]=1;
                rowsame[j+1][i]=1;
                rowsame[j+2][i]=1;
            }
        }
    }
    //按列查找相同
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(nums[j][i]==nums[j+1][i]&&nums[j][i]==nums[j+2][i]){
                columnsame[j][i]=1;
                columnsame[j+1][i]=1;
                columnsame[j+2][i]=1;
            }
        }
    }
    //按行按列分别清零
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            if(rowsame[i][j]!=0){
                nums[j][i]=0;          
            }
        }
        
    }
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            if(columnsame[i][j]!=0){
                nums[i][j]=0;          
            }
        }
        
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