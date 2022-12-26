//xdoj0224.cpp
#include<cstdio>
using namespace std;
//A矩阵2行3列，B矩阵3行2列
int** MartixMultiply(int A[][3],int B[][2],int r,int c){

    int **C=new int*[r];
    for(int i=0;i<r;++i){
        C[i]=new int[c];
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            C[i][j]=0;
            for(int k=0;k<c;++k){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return C;
}
int main(){
    int A[2][3];
    int B[3][2];
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<2;++j){
            scanf("%d",&B[i][j]);
        }
    }

    int** C=MartixMultiply(A,B,2,3);

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}