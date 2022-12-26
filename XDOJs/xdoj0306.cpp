//xdoj0306.cpp
#include<cstdio>
#include<stack>
using namespace std;

int main(){
    stack<int> S;
    char input[100];
    scanf("%s",input);
    //push and calculate
    for(int i=0;i<100;++i){
        if(input[i]=='\0'){
            break;
        }
        if(input[i]>='0'&&input[i]<='9'){
            S.push((int)input[i]-48);
        }else if(input[i]=='+'){
            int a=S.top();//ascii转int
            S.pop();
            a=a+S.top();
            S.pop();
            S.push(a);
        }else if(input[i]=='-'){
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            S.push(b-a);
        }else if(input[i]=='*'){
            int a=S.top();//ascii转int
            S.pop();
            a=a*S.top();
            S.pop();
            S.push(a);
        }else if(input[i]=='/'){
            //没规定无法整除的情况，先试试
            int a=S.top();//ascii转int
            S.pop();
            int b=S.top();
            S.pop();
            S.push(b/a);
        }
    }
    int t=S.top();
    printf("%d",t);
    return 0;
}