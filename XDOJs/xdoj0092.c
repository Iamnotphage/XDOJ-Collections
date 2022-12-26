#include <stdio.h>
int main(){
    int i;
	scanf("%d",&i);
    printf("%d ",i/100);
	i%=100;
	printf("%d ",i/50);
	i%=50;
	printf("%d ",i/20);
	i%=20;
	printf("%d ",i/10);
	i%=10;
	printf("%d ",i/5);
	i%=5;
	printf("%d ",i);
	return 0;
}