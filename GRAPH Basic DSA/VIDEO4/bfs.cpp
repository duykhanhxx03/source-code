#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
// \duyet theo chieu rong: vo huong
// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
using namespace std;
vector<int> Graph[1001];
bool visited[1001];
void bfs (int u){
    visited[u]=true;
    queue<int> qu;
    qu.push(u);
    while (!qu.empty()){
        int v=qu.front();
        qu.pop();
        cout<<v<<" ";
        for (auto x:Graph[v]){
            if (visited[x]==false){
                qu.push(x);
                visited[x]=true;
            }
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
    bfs(1);
    return 0;
}