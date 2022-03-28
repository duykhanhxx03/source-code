#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
double trungvi(vector<int> arr){
    int n=arr.size();
    if (n==1) return arr[0];
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    if (n%2!=0){
        return arr[n/2];
    } else return double(arr[n/2-1]+arr[n/2])/2;
}
int main(){
    string path; cin>>path;
    ifstream filein (path);
    vector<int> res;
    int n; filein>>n;
    for (int i=0; i<n; i++){
        int temp; filein>>temp;
        res.push_back(temp);
    }
    cout<<trungvi(res);
    filein.close();
    return 0;
}