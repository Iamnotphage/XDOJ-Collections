//xdoj0244.c
#include<stdio.h>
#include<string.h>
//选择排序 和 冒泡排序分别过不了编号为 795和 797的例子
//也不知道是不是不稳定排序的问题
//题目貌似也没说明首字母一样的情况怎么排序
void wd_sort(char str[][20],int N){
    int i,j,flag,temp;
    char t[20];
    for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(str[j][0]>str[j+1][0]){
                //利用strcpy进行 整行换行
				strcpy(t,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);
			}
		}
	}
}
//也可以if strcmp(str[min][0],str[j][0])==1
int main(){
    char str[10][20]={'\0'};
    int N;
    scanf("%d",&N);
    if(N>0&&N<=10){
        printf("\n");
        for(int i=0;i<N;i++){
            scanf("%s",&str[i]);
        }
        wd_sort(str,N);
        for(int i=0;i<N;i++){
		    puts(str[i]);
		    printf("\n");
	    }
    }
    return 0;
}