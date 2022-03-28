#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
int main(){
    int n; cin>>n;
    for (int i=0; i<n; i++){
        string s; cin>>s; int n; cin>>n;
        bool is_true=0;
        for (int j=0; j<s.size(); j++){
            if (s[j]==(n+48)){
                cout<<j<<endl;
                is_true=1;
                break;
            }
            if (is_true==1) break;
        }
        if (is_true==0) cout<<-1<<endl;
        
    }
    return 0;
}