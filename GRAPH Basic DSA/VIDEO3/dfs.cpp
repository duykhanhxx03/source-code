#include <iostream>
#include <vector>
#include <cstring>
// \duyet theo chieu sau: vo huong
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
using namespace std;
vector<int> Graph[1001];
bool visited[1001];
void dfs (int u){
    cout<<u<<" ";
    visited[u]=true;
    for (auto x: Graph[u]){
        if (!visited[x]) {
            dfs(x);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for (int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    memset(visited,false, sizeof(visited));
    system("cls");
    dfs(1);
    return 0;
}