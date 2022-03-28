#include <iostream>
#include <vector>
using namespace std;
string combine(const vector<string>&words){
    vector <string> clone (words.begin(), words.end());
    for (int i=0; i<clone.size(); i++){
        for (int j=i+1; j<clone.size(); j++){
            if (clone[i].size()<clone[j].size()){
                string temp=clone[i];
                clone[i]=clone[j];
                clone[j]=temp;
            }
        }
    }
    string res="";
    for (auto x:clone){
        res+=x+" ";
    }
    return res;
}
int main(){
    string s[]={"this", "is", "a", "test"};
    vector <string> a(s,s+4);
    cout<<combine(a);
    return 0;
}