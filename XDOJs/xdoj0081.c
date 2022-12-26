//xdoj0081.c
#include<stdio.h>
#include<string.h>
int main(){
	char str[101][100],copy[101][100];
	char son[101],lowson[101];//son子串 str1用来存储小写的son 
	int i,j,n,mode;
	scanf("%s",son);
	scanf("%d",&mode);
    scanf("%d",&n);//n个数
	for(i=0;i<n;i++){
		scanf("%s",str[i]);//二维数组存储n个字符串
	}
	if(!mode){//大小写不敏感的模式
		strcpy(lowson,son);
		for(j=0;j<strlen(lowson);j++){
			if(lowson[j]>='A'&&lowson[j]<='Z'){
                lowson[j]+=32;//大写改小写
            }
		}
		for(i=0;i<n;i++){
            strcpy(copy[i],str[i]);//输入的字符串全部按行赋值给copy
        }
		for(i=0;i<n;i++){
			for(j=0;j<strlen(copy[i]);j++){//转小写 
				if(copy[i][j]>='A'&&copy[i][j]<='Z'){
                    copy[i][j]+=32;
                }
			}
		}
		for(i=0;i<n;i++){
			if(strstr(copy[i],lowson)!=NULL){//strstr函数 返回在 copy 中第一次出现 lowson 字符串的位置，如果未找到则返回 null
                puts(str[i]);//只要有子串，就输出原来的字符串
            }
		}
	}else{
		for(i=0;i<n;i++){
			if(strstr(str[i],son)!=NULL){
                puts(str[i]);
            }
		} 
	}
	return 0;
}