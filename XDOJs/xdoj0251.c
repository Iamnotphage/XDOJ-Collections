//xdoj0251.c
#include<stdio.h>
int main(){
    typedef struct date{
        int year;
        int month;
        int day;
    }DATE;
    DATE input;
    scanf("%d,%d,%d",&input.year,&input.month,&input.day);
    int sum;
    switch (input.month) // 先计算某月以前月份的总天数
    {
        case 1:sum = 0;
            break;
        case 2:sum = 31;
            break;
        case 3:sum = 59;
            break;
        case 4:sum = 90;
            break;
        case 5:sum = 120;
            break;
        case 6:sum = 151;
            break;
        case 7:sum = 181;
            break;
        case 8:sum = 212;
            break;
        case 9:sum = 243;
            break;
        case 10:sum = 273;
            break;
        case 11:sum = 304;
            break;
        case 12:sum = 334;
            break;
    }
    sum = sum + input.day;
    int leap;
    if (input.year % 400 == 0 || (input.year % 4 == 0 && input.year % 100 != 0)) {
        leap = 1;
    } else {
        leap = 0;
    }
    if (leap == 1 && input.month > 2) { // 如果是闰年且月份大于2,总天数应该加一天
        sum++;
    }
    printf("%d",sum);
    return 0;
}