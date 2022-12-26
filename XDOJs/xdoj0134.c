//xdoj0134.c
#include<stdio.h>
const long long maxn = 1e10;
void swap(int*a ,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    long long n;
    int i=0,j,max,len;//2^31-1 > 10 0000 0000
    int nums[10]={0};
    scanf("%lld",&n);
    if(n>0&&n<maxn){
        while(n!=0){
            nums[i++]=n%10;
            n/=10;
        }
        len=i;
        for(i=0;i<len-1;i++){
            for(j=i+1,max=i;j<len;j++){
                if(nums[max]<nums[j]){
                    max=j;
                }
            }
            if(max!=i){
                swap(&nums[max],&nums[i]);
            }
        }
        for(i=0;i<len;i++){
            printf("%d ",nums[i]);
        }
    }
    return 0;
}