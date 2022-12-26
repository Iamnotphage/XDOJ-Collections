//xdoj0242.c
#include<stdio.h>
int main(){
    struct student{
        int idnum;
        char name[20];
        double s1;
        double s2;
        double s3;
        double avg;
    };
    int n;
    scanf("%d",&n);
    struct student stu[100];
    for(int i=0;i<n;i++){
        scanf("%d %s %lf %lf %lf",&stu[i].idnum,&stu[i].name,&stu[i].s1,&stu[i].s2,&stu[i].s3);
        stu[i].avg=(stu[i].s1+stu[i].s2+stu[i].s3)/3;
    }
    int i,j,max;
    struct student t;
    for(i=0;i<n-1;i++){
        for(j=i,max=i;j<n;j++){
            if(stu[max].avg<stu[j].avg){
                max=j;
            }
        }
        if(max!=i){
            t=stu[i];
            stu[i]=stu[max];
            stu[max]=t;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %s %.1lf\n",stu[i].idnum,stu[i].name,stu[i].avg);
    }
    return 0;
}