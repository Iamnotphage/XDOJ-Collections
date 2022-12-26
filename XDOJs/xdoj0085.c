//xdoj0085.c
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s1[101],s2[101],t[101];
	int i,j;
	double max=0;
	int a[100][100]={0};//100*100的行列式
	double similar;
	gets(s1);
	gets(s2);
	for(i=0;i<strlen(s1);i++){
		for(j=0;j<strlen(s2);j++){
			if(s1[i]==s2[j]||abs(s1[i]-s2[j])==32){//如果字母一样(忽略大小写)
				if(i!=0&&j!=0){
				    a[i][j]=a[i-1][j-1]+1;//a[i][j]左上角数字的索引是a[i-1][j-1]
                }else{
                    a[i][j]=1;
                }
			}
		}
	}
    //查找100*100行列式中的最大值
	for(i=0;i<strlen(s1);i++){
		for(j=0;j<strlen(s2);j++){
			if(a[i][j]>max){
                max=a[i][j];
            }
		}
	}
	similar=2.0*max/(strlen(s1)+strlen(s2));
	printf("%.3f",similar);
    return 0;
}