//xdoj0113.c
//编写程序，根据某城市普通出租车收费标准进行车费计算。标准如下：
//起步里程为3公里，起步费10元；
//超出起步里程后10公里内，每公理2元；
//超过10公里以上的部分加收50%的回空补贴费，即每公里3元；
//营运过程中，因路阻及乘客要求临时停车等待的，按每5分钟2元计费(不足5分钟不收费)。
#include <stdio.h>
int main(){
	float km,price=0; 
	int min;
	scanf("%f%d",&km,&min);
	if(km>10){
        price=3*(km-10)+10 +14;
    }else if(km>3){
        price=2*(km-3)+10;
    }else{
        price = 10;
    }
	price+=min/5*2;
	printf("%.0f", price);
	return 0;
}