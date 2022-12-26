//xdoj0050.c
#include<stdio.h>
int swap(int *a,int *b){//总共用到三处俩个变量互换，特此剔出声明
	int t;
	t=*a;
	*a=*b;
	*b=t;
	return 0;
}
void DoubleSort(int a[],int length,int b[]){//排序魔改版，qq号和位数合一一映射
    int i,j,t;
    for (i=0;i<length-1;i++){
		for (j=i+1;j<length;j++){
			if (a[i]>a[j]){
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
			}
		}
	}
}
int main(){
    int n,t;
    int qq[99];
    int sum[99];
    int qqcopy[99];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&qq[i]);
    }
    for (int i=0;i<n;i++){
		qqcopy[i]=qq[i];
		sum[i]=0;
		for (qq[i];qq[i]>=1;qq[i]/=10) {
			sum[i]+=qq[i]%10;
		}
	}
    DoubleSort(sum,n,qqcopy);
    for(int i=0;i<n;i++){//合相等且qq号比较大
		if(sum[i]==sum[i+1]&&qqcopy[i]>qqcopy[i+1]){
           swap(&qqcopy[i],&qqcopy[i+1]);
        }
	}
    printf("%d",qqcopy[n-1]);//最后一个肯定是最大的了
    return 0;
}  