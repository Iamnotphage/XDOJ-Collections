//xdoj0164.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void SelectionSort(int a[],int length){
    int i,j,t,min;
    for(i=0;i<length-1;i++){
        for(j=i+1,min=i;j<length;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
    }
}
const int N=80;
int main(){
    char str[N];
    int alpha[N];
    gets(str);
    int j=0;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(isalpha(str[i])){
            if(islower(str[i])){
                str[i]-=32;
            }
            alpha[j++]=str[i];
        }
    }
    SelectionSort(alpha,j);
    j=0;
    for(int i=0;i<len;i++){
        if(isalpha(str[i])){
            printf("%c",alpha[j++]);
        }else{
            printf("%c",str[i]);
        }
    }
    return 0;
}