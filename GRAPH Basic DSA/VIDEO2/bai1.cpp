#include <iostream>
// danh sach canh -> ma tran ke
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
int Graph [1001][1001];
int main(){
    int n,m; cin>>n>>m;
    for (int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        Graph[x][y]=Graph[y][x]=1;
        //Graph[x][y]=1; do thi co huong
    }
    system("cls");
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}