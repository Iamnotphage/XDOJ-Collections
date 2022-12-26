//xdoj0172.c
#include<stdio.h>
int ans=0;
int n;
void dfs(int num,int space,int i,int sum){
	if(i==n+1){//结束标志
		if(space==0){
			if(sum==0){
				ans++;
            }
		}
		return;
	}else if(i<n+1){//遍历候选的节点
		dfs(0,0,i+1,sum+10*space+i);//加法
		if(i>1&&num!=i-1){
			dfs(0,0,i+1,sum-10*space-i);//减法
		}
		if(i<n){
			dfs(num+1,10*space+i,i+1,sum);
        }
	}
	return;
}

int main(){
    scanf("%d",&n);
    if(n<3||n>9){
        return 0;
    }
    dfs(0,0,1,0);
    printf("%d",ans);
    return 0;
}