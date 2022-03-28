#include <iostream>
#include <vector>
// danh sach canh -> danh sach ke
// 5 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5
using namespace std;
vector<int> Graph[1001];
int main(){
    int n,m; cin>>n>>m;
    for (int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    system("cls");
    for (int i=1; i<=n; i++){
        if (Graph[i].size()!=0) cout<<i<<": ";
        for (int j=0; j<Graph[i].size(); j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}