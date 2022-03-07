#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n; cin>>n;
	vector <double> arr;
	double temp;
	for (int i=0; i<n; i++){
		 cin>>temp;
		arr.push_back(temp);
	}
	cin>>temp; arr.push_back(temp);
	sort(arr.begin(), arr.end());
	for (int i=0; i<n+1; i++){
		cout<<fixed<<setprecision(2)<<arr[i]<<" ";
	}
	return 0;
}