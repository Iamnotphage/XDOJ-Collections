//xdoj0299.c
#include <stdio.h>
#include <math.h>
int main(){
    int p,c;
    int t;
    scanf("%d",&p);
    t=(p-1)/1e5;
    switch(t){
    case 0:
        c=p*0.1;
        break;
    case 1:
        c=(p-1e5)*0.075+1e5*0.1;
        break;
    case 2:
    case 3:
        c=(p-2e5)*0.05+1e5*0.1+1e5*0.075;
        break;
    case 4:
    case 5:
        c=(p-4e5)*0.03+1e5*0.1+1e5*0.075+2e5*0.05;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        c=(p-6e5)*0.015+1e5*0.1+1e5*0.075+2e5*0.05+2e5*0.03;
        break;
    default:
        c=(p-1e6)*0.01+1e5*0.1+1e5*0.075+2e5*0.05+2e5*0.03+4e5*0.015;
    }
    printf("%d\n",c);
    return 0;
}