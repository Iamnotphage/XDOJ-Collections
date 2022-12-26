//xdoj0087.c
#include<stdio.h>
int main(){
    int i,l,j;
	int count;
	int sum=0;
	int num[1000];
	for(i=0;i<1000;i++){
		scanf("%d",&num[i]);
		if(num[i]==0){
            break;
        }
	}
	for(i=0;i<1000;i++){
		count=1;
		if(num[i]==1){
            sum+=1;
        }
		if(num[i]==2){
			if(i==0||num[i-1]==1){
                sum+=2;
            }else{
				for(j=i-1;j>=0;j--){
					if(num[j]==2){
                        count+=1;
                    }else{
                        break;
                    }
				}
				sum+=2*count;
			}
		}
        if(num[i]==0){
			sum+=0;
			break;
		}
	}
	printf("%d",sum);
	return 0;
}
