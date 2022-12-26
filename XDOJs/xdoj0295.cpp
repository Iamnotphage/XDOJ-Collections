//xdoj0295.cpp
#include<iostream>
#define MAX_SIZE 100
using namespace std;

typedef struct List{
    int length;
    int arr[MAX_SIZE];
}List;

void CreateList(List &L){
    for(int i=0;i<L.length;++i){
        cin>>L.arr[i];
    }
}

void Merge(List L1,List L2,List& Res){
    Res.length=0;
    int p1=0,p2=0,p3=0;
    while(p1<L1.length && p2<L2.length){
        if(L1.arr[p1]==L2.arr[p2]){
            Res.arr[p3]=L1.arr[p1];
            p1++;
            p2++;
            p3++;
            Res.length++;
        }else if(L1.arr[p1]<L2.arr[p2]){
            Res.arr[p3]=L1.arr[p1];
            p1++;
            p3++;
            Res.length++;
        }else if(L1.arr[p1]>L2.arr[p2]){
            Res.arr[p3]=L2.arr[p2];
            p2++;
            p3++;
            Res.length++;
        }
    }

    if(p1>=L1.length || p2>=L2.length){
        if(p1>=L1.length){
            while(p2<L2.length){
                Res.arr[p3]=L2.arr[p2];
                p2++;
                p3++;
                Res.length++;
            }
        }else if(p2 >= L2.length){
            while(p1<L1.length){
                Res.arr[p3]=L1.arr[p1];
                p1++;
                p3++;
                Res.length++;
            }
        }
    }


}

void PrintRes(List Res){
    for(int i=0;i<Res.length;++i){
        cout<<Res.arr[i]<<" ";
    }
}

int main(){
    List L1,L2,Res;
    cin>>L1.length>>L2.length;
    CreateList(L1);
    CreateList(L2);
    Merge(L1,L2,Res);
    PrintRes(Res);
    return 0;
}