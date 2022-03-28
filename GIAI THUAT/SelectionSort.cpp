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
    int n=9;
    int a[]={8,3,5,8,9,4,3,4,0};
    selectionsort(a,n);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}