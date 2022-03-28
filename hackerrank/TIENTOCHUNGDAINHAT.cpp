#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n; cin>>n;cin.ignore();
    int min_size=100;
    vector <string> res; string temp;
    for (int i=0; i<n; i++){
        getline(cin,temp);
        if (temp.size()<min_size) min_size=temp.size();
        res.push_back(temp);
    }
    int result=0;
    bool is_true=1;
    for (int i=0; i<min_size; i++){
        for (int j=0; j<n-1; j++){
            string temp1=res[j];
            string temp2=res[j+1];
            if (temp1[i]!=temp2[i]){
                is_true=0;
                break;
            }
        }
        if (is_true==1) result++; else break;
    }
    cout<<res[0].substr(0,result);
    return 0;
}