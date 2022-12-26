//xdoj0045.c
#include<stdio.h>
#include<math.h>//fabs()里面要浮点数
int main(){
    int n,max;
    scanf("%d",&n);
    int t[30];
    if(n>=2&&n<=30){
        for(int i=0;i<n;i++){
            scanf("%d",&t[i]);
        }
        max=fabs((double)t[0]-t[1]);//假设波动最大的是前俩项差
	    for(int i=0; i <n-1;i++){
            if(fabs((double)t[i+1]-t[i])>max){
                max=fabs((double)t[i + 1]-t[i]);
		    }
	    }
        printf("%d",max);
    }
    return 0;
}