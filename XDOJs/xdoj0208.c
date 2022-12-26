//xdoj0208.c
#include<stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void sort(int *num,int length){
    int i,j,min;
    for(i=0;i<length-1;i++){
        for(j=i,min=i;j<length;j++){
            if(num[min]>num[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(&num[i],&num[min]);
        }
    }
}
int main(){
    int n,t,evennum[20],oddnum[20],j=0,k=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t%2==0){
            evennum[j++]=t;
        }else{
            oddnum[k++]=t;
        }
    }
    sort(evennum,j);
    sort(oddnum,k); 
    for(int i=0;i<k;i++){
        printf("%d ",oddnum[i]);
    }
    printf(" ");
    for(int i=0;i<j;i++){
        printf(" %d",evennum[i]);
    }
    return 0;
}