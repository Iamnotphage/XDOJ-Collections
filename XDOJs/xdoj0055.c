//xdoj0055.c
#include<stdio.h>
int main(){
	int n;
	int i;
	double t,num,sum=0;
	double b=1,a=2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum=sum+a/b;
		t=a;
		a=b+a;
		b=t;
	}
    printf("%.2f",sum); 
	return 0;
}