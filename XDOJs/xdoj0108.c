//xdoj0308.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[100]={'\0'};
char nums[100]={'\0'};
int gcd(int a){
    int flag=1,i;
    for(i=2;i<a/2;i++){
        if(a%i==0){
            flag=0;
            break;
        }
    }
    if(flag){
        return a;
    }else{
        return a/i;
    }
}
int main(){
    gets(str);
    int len=strlen(str);
    int num=0,c=1,k=0;
    for(int i=0;i<len;i++){
        if(isdigit(str[i])){
            nums[k++]=str[i];
        }
    }
    len=strlen(nums);
    for(int i=len-1;i>=0;i--){
        num=num+((int)nums[i]-48)*c;
        c*=10;
    }
    printf("%d",gcd(num));
    return 0;
}