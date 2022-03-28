#include <iostream>

using namespace std;
#include <vector>
#include <cmath>
bool check(int number){
    if (number<0) return false;
    int temp= int(sqrt(number));
    return temp*temp==number;
}
vector<int> listSquare(int a, int b){
    vector<int> result;
    for (int i=a; i<=b; i++){
        if (check(i)) result.push_back(i);
    }
    return result;
}
int main(){
    int a,b; cin>>a>>b;
    vector <int> arr=listSquare(a,b);
    for (auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}