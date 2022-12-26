//xdoj0034.c
#include<stdio.h>
int function(int a,int b){
    int count=0;
    int n=3,x,y,z,f,t;
    if(a>=b){
       t=a;
       a=b;
       b=t; //确保b是大的那个数
    }
    for(int i=a;i<=b;i++){
        t=i;
        if(i>999){
            n=4;
        }
        switch(n){
            case 3:
                x=i/100;
                y=(i/10)%10;
                z=i%10;
                if(i==x*x*x+y*y*y+z*z*z){
                    count++;
                }
                break;
            case 4:
                x=i/1000;
                y=(i/100)%10;
                z=(i/10)%10;
                f=i%10;
                if(i==x*x*x*x+y*y*y*y+z*z*z*z+f*f*f*f){
                    count++;
                }
                break;
            default:break;
        }
    }
    return count;
}
int main(){
    printf("%d",function(3,1000));
    return 0;
}