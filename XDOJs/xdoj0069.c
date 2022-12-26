//xdoj0069.c
#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int nums[100][100]={0};//越界部分是0，便于判断
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    int count=0;
    int flag,max,index;
    for(int i=0;i<m;i++){
        flag=0;
		count=0;
		index=0;
		max=0;
		for(int j=0;j<=n;j++){//必须要让j<=n,越界后才会出现0,否则全是1的情况出错
			if(nums[i][j]==1){
				count++;
				flag=1;//非全零
			}else{
				if(count>max){
					max=count;
					index=j-1;//索引j的上一个数就是1，当前j是0
				}
				count=0;
			}
		}
		if(flag){
            printf("%d %d\n",index-max+1,index);
        }else{//全是零
            printf("-1 -1\n");
        }
    }
    return 0;    
}