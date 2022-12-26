//xdoj0039.c
#include<stdio.h>
int main(){
    int m,n,flag=0;
    scanf("%d%d",&m,&n);
    int nums[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    int max[100],min[100];
    int i,j;
    for(i=0;i<m;i++){
		min[i]=nums[i][0];
		for(j=1;j<n;j++){
			if(nums[i][j]<min[i]) min[i]=nums[i][j];
		}
		
	}
	for(j=0;j<n;j++){
		max[j]=nums[0][j];
		for(i=1;i<m;i++){
			if(nums[i][j]>max[j]){
                max[j]=nums[i][j];
            }
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(nums[i][j]==max[j]&&nums[i][j]==min[i]){
				printf("%d %d %d",i,j,nums[i][j]);
				flag=1;
			}
		}
	}
	if(flag==0){
        printf("no");
    }
    return 0;
}