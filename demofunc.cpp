#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <double> arr;
    double temp;
    int n; cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        arr.push_back(temp);
    }
    reverse(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        cout<<fixed<<setprecision(2)<<arr[i]<<" ";
    }
    return 0;
}