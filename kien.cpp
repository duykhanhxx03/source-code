#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
string process(string s){
    stringstream ss(s);
    string token="";
    string temp="";
    while (ss>>token){
        temp+=token;
    }
    return temp;
}
int main(){
    int n; cin>>n;
    cin.ignore();
    for (int i=0; i<n; i++){
        string temp; getline(cin,temp);
        temp=process(temp);
        cout<<temp<<" ";
    }
    return 0;
}