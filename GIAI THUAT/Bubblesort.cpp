#include <iostream>
using namespace std;
void bubblesort (int a[], int n){
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<i; j++){
            if (a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
int main(){
    int n=9;
    int a[]={8,3,5,8,9,4,3,4,0};
    bubblesort(a,n);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}