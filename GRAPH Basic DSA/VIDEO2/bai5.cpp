#include <iostream>
#include <sstream>
// danh sach canh -> ma tran ke
// 5
// 2 3 4
// 1 3 4 5
// 1 2 4 5
// 1 2 3 5
// 2 3 4
using namespace std;
int Graph [1001][1001];
int main(){
    int n; cin>>n; cin.ignore();
    for (int i=1; i<=n; i++){
        string temp="",token;
        getline(cin,temp);
        stringstream ss(temp);
        while (ss>>token){
            Graph[i][stoi(token)]=1;
            Graph[stoi(token)][i]=1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
    //system("cls");
    return 0;
}