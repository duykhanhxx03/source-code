#include <iostream>
// danh sach canh -> ma tran ke
// 5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
using namespace std;
int Graph [1001][1001];
int main(){
    int n; cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int x; cin>>x;
            Graph[i][j]=x;
        }
    }
    system("cls");
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (Graph[i][j]&&i<j) cout<<i<<" "<<j<<endl; 
        }
    }
    return 0;
}