#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int x){
	int right=n-1, left=0; 
	while (right>left){
		int mid=(right+left)/2;
		if (a[mid]<x){
			left=mid+1;
		} else {
			right=mid;
		}
	}
	if (a[left]==x) return left;
	return -1;
}

int main(){
	int n; cin>>n;
	int x=5;
	int a[10]={1,2,3,4,5,6,7,8,9,10};

	return 0;
}