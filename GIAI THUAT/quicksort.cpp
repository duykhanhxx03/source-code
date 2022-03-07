#include <iostream> 
using namespace std;
int partition(int a[], int left, int right){
    int vt=left-1;
    int pivot=a[right];
    for (int i=left; i<=right-1; i++){
        if (a[i]<pivot){
            vt++;
            swap(a[i],a[vt]);          
        }
    }
    vt++;
    swap(a[vt],a[right]);
    return vt;
}
void quicksort(int a[], int left, int right){
    if (right>left){
        int ipivot=partition(a,left,right);
        quicksort(a,left,ipivot-1);
        quicksort(a,ipivot+1,right);
    }
}
void sortAscending(float array[], int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (array[j]<array[i]) swap(array[j], array[i]);
        }
    }
}
void reverseArray(float array[], int size){
    for (int i=0; i<size/2; i++){
        swap(array[i], array[size-i-1]);
    }
}
void sort(float array[], int size, bool isAscending){
    sortAscending(array,size);
    if (isAscending==false) reverseArray(array,size);
}
int main(){
    float a[]={28,16,57,99,81,22,66,72};
    int n=8;
    sort(a,n,0);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}