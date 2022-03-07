#include <iostream>
using namespace std;
void ChanVeDau(int a[], int n){
    int vt=-1;
    for (int i=0; i<=n-1; i++){
        if (a[i]%2==0){
            vt++;
            swap(a[i], a[vt]);
        }
    }
}
int main(){
    int a[]={28,16,57,99,81,22,66,72};
    int n=8;
    ChanVeDau(a,n);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}