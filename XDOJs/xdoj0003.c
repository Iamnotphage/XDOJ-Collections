//xdoj0003.c
#include <stdio.h>
int main(){
	int n,i,j,k,t,min;
	scanf("%d",&n);
	int a[1000],b[999];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++)
		   if(a[k]>a[j])
		        k=j;
		if(k!=i){
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
	for(i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(min=b[0],i=0;i<n-1;i++)
	   if(min>b[i])
	   	  min=b[i];
	printf("%d",min);
	return 0;
}
