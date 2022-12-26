//xdoj0177.c
#include<stdio.h>
#include<string.h>
int main(){
    char str[101]={'\0'};
    int sum=0;
    gets(str);//scanf("%s",&str);scanf不行
    //因为scanf不能输入空格，gets可以接收空格,估计是xdoj例子里面有一个输入了空格
    for(int i=0;str[i]!='\0';i++){
        sum+=(int)str[i];//算出十进制的合
    }
    //再转化为2进制，取后面一字节，也就是后八位
    printf("%d",sum&255);
    //(255二进制是1111 1111 只有后八位是1，& 运算后sum只保留了二进制的后八位,再用%d输出后变成了10进制)
    return 0;
}