//xdoj0007.c
#include<stdio.h>
int main(){
    int day,fog,num;
    int nums[10]={1,2,3,4,5,6,7,8,9,0};
    scanf("%d%d%d",&day,&fog,&num);
    if(day>=6||fog<200){//不限行的情况
        printf("%d no",num%10);
    }else if(day>0&&day<6&&fog>=200&&fog<400){//周一到周五且200-400的限行
        if(num%10==nums[day-1]||num%10==nums[day+4]){//yes
            printf("%d yes",num%10);
        }else{
            printf("%d no",num%10);//no
        }
    }else if(day>0&&day<6&&fog>=400&&fog<600){//周一到周五且大于400
        //偶数周情况
        if(day%2==0){//yes
            if(num%10==0||num%10==2||num%10==4||num%10==6||num%10==8){
                printf("%d yes",num%10);
            }else{
                printf("%d no",num%10);
            }
        }else{//奇数周情况
            if(num%10==1||num%10==3||num%10==5||num%10==7||num%10==9){
                printf("%d yes",num%10);//yes
            }else{
                printf("%d no",num%10);//no
            }
        }

    }
    return 0;
}