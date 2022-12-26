//xdoj0267.cpp
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int PushSq[1000];//第二行的数据
int flag[1000];//标记正确与否
int data[1000];//需要判断的数据
int main(){
	int M,N,K;//栈的最大长度，压栈数据长度，测试数据数
    cin>>M>>N>>K;
    //压栈数据
    for(int i=0;i<N;++i){
        cin>>PushSq[i];
    }
    for(int i=0;i<K;++i){
        for(int j=0;j<N;++j){
            cin>>data[j];//一行一行判断，输入需要判断的数据data
        }
        stack<int> s;//在内部循环，无需重新清空
        int p=0,j=0;//p操作PushSq j操作data
        while(s.size()<=M && j<N && p<=N){//只要栈不满，p，j没越界
            if(!s.empty() && s.top()==data[j]){
                s.pop();
                j++;//需要验证的序列 指针右移
            }else{
                if(s.size()<=M && p<N){
                    //栈未满且p未越界
                    s.push(PushSq[p]);
                }
                ++p;
            }
        }
        if(s.empty()){//如果栈空，说明全部都对的上，说明正确
            flag[i]=1;
        }else{//栈非空，存在错误
            flag[i]=0;
        }
    }
    for(int i=0;i<K;++i){
        if(flag[i]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
	return 0;
}