//xdoj0135.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void swap(int* a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void sort(int* nums,int length){
    int i,j,max;
    for(i=0;i<length-1;i++){
        for(j=i+1,max=i;j<length;j++){
            if(nums[max]<nums[j]){
                max=j;
            }
        }
        if(max!=i){
            swap(&nums[max],&nums[i]);
        }
    }
}
int main(){
    char str[105]={'\0'};
    gets(str);
    int len=strlen(str);
    int nums[100]={0};
    int stack[100]={0},k=0,j=0,t=0,count=0;
    for(int i=0;i<len;i++){
        if(isdigit(str[i])){
            for(;str[i]!='\0' && isdigit(str[i]);i++){
                stack[k++]=(int)str[i]-48;
            }
            if(k==1){
                nums[j++]=stack[0];
                count++;
            }else{
                t=stack[0];
                for(int v=1;v<k;v++){
                    t*=10;
                    t+=stack[v];
                }
                nums[j++]=t;
                count++;
            }    
            t=0;
            k=0;
        }
    }
    sort(nums,count);
    for(int i=0;i<count;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}