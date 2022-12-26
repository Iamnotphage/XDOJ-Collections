//xdoj0333.cpp
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef struct Node{
    vector<int> pos;
    bool isOutput;
}Node;

void InitNodes(Node nodes[],char* str){
    int len=strlen(str);
    for(int i=0;i<len;++i){
        nodes[str[i]].pos.push_back(i);//vector加入位置
        nodes[str[i]].isOutput=false;
    }
}

void Output(Node nodes[],char* str){
    int len=strlen(str);
    for(int i=0;i<len;++i){
        if(nodes[str[i]].pos.size()>1 && !nodes[str[i]].isOutput){
            //有重复且没被输出过
            for(int j=0;j<nodes[str[i]].pos.size();++j){
                printf("%c:%d",str[i],nodes[str[i]].pos.at(j));
                if(j!=nodes[str[i]].pos.size()-1){
                    printf(",");
                }
                nodes[str[i]].isOutput=true;
            }
            printf("\n");
        }
    }
}

int main(){
    Node nodes[128];//只由数字和字母组成
    char input[101];
    scanf("%s",input);
    InitNodes(nodes,input);
    Output(nodes,input);
    return 0;
}