//xdoj0211.c
#include<stdio.h>
int main(){
    double stu[5][4],sum=0,avg=0;
    int c1=0,countF=0,countW=0,flag=1;
    for(int i=0;i<5;i++){
        c1=0;//不及格科目数
        avg=0;
        flag=1;
        for(int j=0;j<4;j++){
            scanf("%lf",&stu[i][j]);
            if(stu[i][j]<60){
                c1++;//判断不及格
            }
            avg+=stu[i][j];//计算一个学生的平均成绩
            if(stu[i][j]<85){
                flag=0;
            }
        }
        if(avg>=360||flag==1){//判断优秀 4*90=360
            countW++;
        }
        sum+=stu[i][0];//第一门课的总和
        if(c1>=2){
            countF++;//2门及以上不及格人数
        }
    }
    printf("%.1lf %d %d",sum/5,countF,countW);
    return 0;
}