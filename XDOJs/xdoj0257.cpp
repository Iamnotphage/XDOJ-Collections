//xdoj0257.cpp
//最长公共子串，并计算相似度
/*  注意有空格输入，他妈的
    s h i t o
m   0 0 0 0 0
i   0 0 1 0 0
t   0 0 0 2 0
m   0 0 0 0 0
i   0 0 1 0 0
t   0 0 0 2 0
o   0 0 0 0 3
LCS等价于max，每次给矩阵赋值就刷新一下
*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int Martix[100][100];
    int LCS=0;
    string S1;
    string S2;
    getline(cin,S1);
    getline(cin,S2);
    int l1=S1.length();
    int l2=S2.length();
    for(int i=0;i<l1;++i){
        if(S1.at(i)>=65 && S1.at(i)<=90){
            S1.at(i)+=32;//是大写字母就改为小写
        }
    }
    for(int i=0;i<l2;++i){
        if(S2.at(i)>=65 && S2.at(i)<=90){
            S2.at(i)+=32;//是大写字母就改为小写
        }
    }
    for(int i=0;i<l2;++i){//i操作s2
        for(int j=0;j<l1;++j){//j操作s1
            if(S2.at(i)==S1.at(j)){
                //字符匹配上了
                if(i==0||j==0){
                    //如果是矩阵的边界，则直接赋值1
                    Martix[i][j]=1;

                    if(LCS<Martix[i][j]){
                        LCS=Martix[i][j];//刷新最大值
                    }
                }else{
                    //对角线加1
                    Martix[i][j]=Martix[i-1][j-1]+1;

                    if(LCS<Martix[i][j]){
                        LCS=Martix[i][j];//刷新最大值
                    }
                }
            }else{
                //不一样
                Martix[i][j]=0;
            }
        }
    }
    cout<<LCS<<endl;
    //记得三位小数
    printf("%.3lf",2*(double)LCS/(l1+l2));

    return 0;
}