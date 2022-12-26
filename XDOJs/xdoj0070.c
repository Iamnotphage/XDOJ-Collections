//xdoj0070.c
#include<stdio.h>
void ZigzagScan(int nums[100][100],int n){
    int i,j;//总共n*n个数，2*n-1个斜线 操作2n-1次，i是行，j是列
    int count;//总共要扫描2n-1次，分成俩个部分 n 和 n-1
    int total=2*n-1;
    for(count=1;count<=total;count++){//扫描前半部分的n组斜线
        if(count%2==0){//偶数，斜线的起点行号是0 从右上到左下
            for(i=0;count-1-i!=-1;i++){
                if(nums[i][count-1-i]!=1001){
                    printf("%d ",nums[i][count-1-i]);//行列标相加是count-1
                }
            }
        }else{//奇数，斜线的起点列号是0 从左下到右上
            for(j=0;count-1-j!=-1;j++){
                if(nums[count-1-j][j]!=1001){
                    printf("%d ",nums[count-1-j][j]);//行列标相加是count-1
                }
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int nums[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            nums[i][j]=1001;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    ZigzagScan(nums,n);
    return 0;
}
