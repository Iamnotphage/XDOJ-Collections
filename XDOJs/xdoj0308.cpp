#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i,top,stack[100],len,num[100];
	int k=0;
	top=-1;//栈为空
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
      if(str[i]>='0'&&str[i]<='9')//操作数
	  {
		  int count=0;
		while(str[i]!=' '&&str[i]!=0)
		{
			count=count*10+str[i]-'0';//计算出正确的数字
			i++;
		}
		num[k++]=count;//数字数组
	  }
	}
	for(i=len-1;i>=0;i--)
	{
	   if(str[i]>='0'&&str[i]<='9')//碰到操作数
	   {
		   top++;
		   stack[top]=num[--k];//将num中的数字压栈
		   while(str[i]!=' ')//利用空格跳过后面的多余数字
			   i--;
	   }
	   if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
	  {
		  int t1,t2;
		  t1=stack[top--];//第一个出栈的数
		  t2=stack[top--];//第二个出栈的数
		  if(str[i]=='+')
			  stack[++top]=t1+t2;//将计算结果压栈
		  if(str[i]=='-')
			  stack[++top]=t1-t2;
		  if(str[i]=='*')
			  stack[++top]=t1*t2;
		  if(str[i]=='/')
			  stack[++top]=t1/t2;
	  }
	}
	printf("%d",stack[top]);
	return 0;
}

