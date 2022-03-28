#include <iostream>
#include <sstream>
#include <vector>
// danh sach canh -> ma tran ke
// 5
// 2 3 4
// 1 3 4 5
// 1 2 4 5
// 1 2 3 5
// 2 3 4
using namespace std;
int Graph [1001][1001];
vector <pair<int,int>> edges;
int main(){
    int n; cin>>n; cin.ignore();
    for (int i=1; i<=n; i++){
        string temp="",token;
        getline(cin,temp);
        stringstream ss(temp);
        while (ss>>token){
            // Graph[i][stoi(token)]=1;
            // Graph[stoi(token)][i]=1;
            if (i<stoi(token))
                edges.push_back(make_pair(i,stoi(token)));
        }
    }
    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout<<Graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //system("cls");
    for (auto x:edges) cout<<x.first<<" "<<x.second<<endl;
    return 0;
}