#include <iostream>
#include <string>
using namespace std;
int palindromeIndex(string s) {
    int left=0, right=s.size()-1;
    int saved_left=left, saved_right=right;
    bool is_true=true;
    if (s.size()>=3){
        while (left<=right){
            if (s[left]!=s[right]){
                if (is_true==false) return saved_right;
                is_true=false;
                saved_left=left;
                saved_right=right;
                left++;
            } else {left++; right--;};
        }
    }
    return is_true? -1:saved_left;
}
int main(){
    int n; cin>>n;
    string a[100];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<n; i++){
         cout<<palindromeIndex(a[i])<<endl;
    }
    return 0;
}