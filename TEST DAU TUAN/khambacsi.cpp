#include <iostream>
using namespace std;
void selectionsort (int a[], int n){
    for (int i=0; i<n-1; i++){
        int lc=i;
        int min=a[i];
        for (int j=i+1; j<n; j++){
            if (a[j]<min) {
                lc=j;
                min=a[j];
            }
        }
          swap(a[lc], a[i]);
    }
}
int main(){
    int n; cin>>n;
    int *T= new int[n];
    for (int i=0; i<n; i++){
        cin>>T[i];
    }
    selectionsort(T,n);
    int res=0;
    for (int i=0; i<n; i++){
        res+=T[i]*(n-(i+1));
    }
    cout<<res;
    delete[]T;
    return 0;
}