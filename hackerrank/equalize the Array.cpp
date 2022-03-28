#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int equalizeArray(vector<int> arr) {
    sort(arr.begin(), arr.end());
    arr.push_back(-1);
    int max_res=1;
    for (int i=0; i<arr.size()-1; i++){
        int count=1;
        if (arr[i]==arr[i+1]){
            for (int j=i; j<arr.size()-1; j++){
                if (arr[j]==arr[j+1]) count++; else {
                    max_res=max(max_res,count);
                    break;
                }
            }
        }
    }
    arr.pop_back();
    return arr.size()-max_res;
}
int main(){
    vector <int> arr={37, 32, 97, 35, 76, 62};
    cout<<equalizeArray(arr);
    return 0;
}