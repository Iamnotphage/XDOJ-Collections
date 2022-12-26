//xdoj0106.cpp
#include<algorithm>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//自己用例： B(kab(hij)A)B 
//注意规则，希腊字母可以表示大写或小写，所以括号内部遇到大写不应该直接翻译
//如上，处理括号后，应该是
//B(kab hjhih A)B
//BkAkhkikhkjkhkbkaB
int main(){
    int p=0;//p用于操作原始语言
    char ch;
    string MonsterWord;//存储原始语言
    stack<char> S;//存储 处理过括号 的语言
    queue<char> Q;
    stack<char> Final;
    cin>>MonsterWord;
    //接下来处理括号
    while(p<MonsterWord.size()){
        //为什么是右括号分界，考虑到括号嵌套的情况，例如B(kh(abc))B
        //要先翻译(abc)
        if(MonsterWord.at(p)!=')'){
            //不是最内层括号的话，就先入栈S
            S.push(MonsterWord.at(p));
        }else if(MonsterWord.at(p)==')'){
            //判断到第一个右括号，也就是最内层的括号
            //开始入队列,注意入队列停止条件是第一个左括号
            while(S.top()!='('){
                //不是左括号，就入队
                Q.push(S.top());
                S.pop();//出栈
            }
            //等于左括号，没入队，但是把S存的左括号出一个
            S.pop();
            //左括号，入队完毕，开始出队，交错出队,并入栈到S
            while(Q.back()!=Q.front()){//只要队列并非只剩一个，就一直交叉入队
                S.push(Q.back());
                S.push(Q.front());
                Q.pop();//弹出第一个元素
            }
            //剩一个，就是所谓的theta
            S.push(Q.back());
            Q.pop();
        }
        ++p;
    }
    //接下来从S中翻译A，B
    while(!S.empty()){
        Final.push(S.top());
        S.pop();
    }
    while(!Final.empty()){
        if(Final.top()=='A'){
            cout<<"sae";
        }else if(Final.top()=='B'){
            cout<<"tsaedsae";
        }else{
            cout<<Final.top();
        }
        Final.pop();
    }
    return 0;
}