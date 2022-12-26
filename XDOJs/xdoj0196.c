//xdoj0196.c
#include<stdio.h>
int main(){
    int i,j,k;
	char n;
	scanf("%c",&n);
	for(i=65;i<=n;i++){//大写A是65,n-i表示行数
		for(j=n-i;j>0;j--){//空格的个数是递减的
			printf(" ");
		}
		for(k=65;k<=i;k++){//从A开始正向输出 ABCDE...
			printf("%c",k);
		}
		for(k=i-1;k>=65;k--){//从中间的字母开始反向输出 ...EDCBA
			printf("%c",k);
		}
		printf("\n");//最外层结束一次，换一次行
	}
    return 0;
}