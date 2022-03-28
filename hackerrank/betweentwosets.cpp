#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int GCD (int a, int b) {return __gcd(a,b);}
int LCM (int a, int b) {return (a*b/__gcd(a,b));}
int getTotalX(vector<int> a, vector<int> b) {
    int res=0;
    int lcm_a=a[0]; int gcd_b;
    for (int i=1; i<a.size(); i++){lcm_a=LCM(lcm_a,a[i]);}
    int min_b=b[0];
    for (auto x:b){min_b=min(min_b,x);};
    int i=lcm_a;
    while(i<=min_b){
        int count=0;
        for (int j=0; j<b.size(); j++){
            if (b[j]%i==0) count++;
        }
        if (count==b.size()) {
            res++;
        }
        i+=lcm_a;
    }
    return res;
}
int main(){
    int m,n; cin>>m>>n;
    vector<int> a,b; int temp=0;
    for (int i=0; i<m; i++){
        cin>>temp; a.push_back(temp);
    }
    for (int i=0; i<n; i++){
        cin>>temp; b.push_back(temp);
    }
    cout<<getTotalX(a,b);
    return 0;
}