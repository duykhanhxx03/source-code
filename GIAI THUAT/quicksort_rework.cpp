#include <iostream>
using namespace std;
int partition(int a[], int left, int right){
    int pivot=a[right];
    int vt=left-1;
    for (int i=left; i<=right-1; i++){
        if (a[i]<pivot){
            vt++;
            swap(a[i], a[vt]);
        }
    }
    vt++;
    swap(a[vt], a[right]);
    return vt;
}
void quicksort(int a[], int left, int right){
    if (right>left){
        int ipivot=partition(a,left,right);
        quicksort(a,left,ipivot-1);
        quicksort(a,ipivot+1,right);
    }
}
int main(){
    int a[]={7,3,6,8,9,9,0,3,2}; int n=9;
    quicksort(a,0,n-1);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}