//xdoj0073.c
//xdoj的例子可能有一个例子是输入了51个字符前49个是字母，后俩个是数字，应该要截取50个
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
//用于计算输入中的数字 a13b2 计算出13 和 2
int calcul(int temp[],int count){
    int t=count;
    int ans=0;
    for(int i=0;i<t;i++){
        ans=ans+temp[i]*pow(10.0,(double)(count-1));//也可以ans=ans*10+(temp[i])
        count--;
    }
    return ans;
}
int main(){
    char input[51];
    int temp[50];
    char t;
    int num=0,count=0;//count表示数字的位数,num表示这个数字
    scanf("%51s",input);
    input[50]='\0';//避免输入四十九个字母后 有一个俩位数导致input变成51个输入
    for(int i=0;i<50;i++,count=0){
        if(isalpha(input[i])&&isdigit(input[i+1])){//字母加数字的情况
            t=input[i];
            for(int j=i+1;isdigit(input[j]);j++){
                temp[count]=(int)input[j]-48;
                count++;
            }
            num=calcul(temp,count);
            //输出部分解压的字符串
            for(int k=0;k<num;k++){
                putchar(t);
            }
        }else if((isalpha(input[i])&&isalpha(input[i+1]))||(isalpha(input[i])&&input[i+1]=='\0')){//连续出现次数小于3时不压缩 ||后面是越界的问题
            putchar(input[i]);
        }
    }
    printf("\n");
    return 0;
}