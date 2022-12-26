//xdoj0273.cpp
#include<cstdio>
using namespace std;

char input[100];

int main(){
    char ch;
    int count=0,len=1;
    while(scanf("%c",&ch) && ch!='#'){
        input[len++]=ch;
    }
    for(int i=1;i<len;++i){
        if(input[i]=='@'){
            continue;
        }else{
            if(i*2>=len){
                printf("%c ",input[i]);
                count++;
            }else{
                if(input[i*2]=='@' && input[i*2+1]=='@'){
                    printf("%c ",input[i]);
                    count++;
                }
            }
        }
    }
    printf("\n%d",count);
    return 0;
}