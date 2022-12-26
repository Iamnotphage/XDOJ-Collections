//xdoj0334.cpp
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int m, n,temp;
    pair<int, int> p; vector<int> v,v1,v2;
    set<int> s, ss; int count;
    vector<pair<int, int> > vv;
    cin >> m;//输入样例数，题目有点坑说要输出m行，其实不是的，而是输出m组
    while (m--){
        cin >> n;//输入接下来要输入的数的个数
        for (int i = 0; i < n; i++){
            cin >> temp;
            v.push_back(temp);//这个向量v容器是为了保存这第一行的n个数
            s.insert(temp);//这个集合s容器是为了实现去重和自动排序
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); it++){
            v1.push_back(*(it));//由于集合容器不能按下标访问，所以我又用一个向量容器保存s中数据
        }
        for (int i = 0; i < n; i++){
            cin >> temp;
            p.first = temp;
            p.second = v[i];
            vv.push_back(p);//向量vv容器是为了建立关系，第一行哪个数对应第二行哪个组
            ss.insert(temp);//这个集合ss容器是为了实现去重和自动排序
        }
        for (set<int>::iterator it = ss.begin(); it != ss.end(); it++){
            v2.push_back(*(it));//由于集合容器不能按下标访问，所以我又用一个向量容器保存ss中数据
        }
        count = 0;
        for (int i = 0; i < v2.size(); i++){//v2存储了有序不重的组号
            cout << v2[i] << "={";
            for (int j = 0; j < v1.size(); j++){//v1存储了有序不重的第一行数（类别号）
                cout << v1[j] << "=";
                for(int k = 0;k<vv.size();k++){//vv存储了第一行与第二行的对应关系
                    if(vv[k].first == v2[i] && vv[k].second == v1[j])//按组号和类别号匹配
                        count++;
                }
                cout << count;
                count = 0;//用完置零
                if (j != v1.size() - 1)
                    cout << ",";
            }
            cout << "}" << endl;
        }
    v.clear(); v1.clear(); v2.clear(); vv.clear();
    s.clear(); ss.clear();
    }
    return 0;
}