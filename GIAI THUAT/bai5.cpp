#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int GCD(int a, int b){
    // Nếu a = 0 => ucln(a,b) = b
    // Nếu b = 0 => ucln(a,b) = a
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; // a = a - b
        }else{
            b -= a;
        }
    }
    return a; // return a or b, bởi vì lúc này a và b bằng nhau
}
int LCM (int a, int b) {return (a*b/GCD(a,b));}
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
    vector <int> a,b; int a_s,b_s; cin>>a_s>>b_s;
    int temp;
    for (int i=0; i<a_s; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<b_s; i++){
        cin>>temp;
        b.push_back(temp);
    }
    cout<<getTotalX(a,b);
    return 0;
}