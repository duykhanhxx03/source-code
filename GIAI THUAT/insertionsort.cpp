#include <iostream>
using namespace std;
void ThemBaoToan(int a[], int &n, int x){
    int vt=n-1;
    for (; vt>=0&&a[vt]>x; vt--){
        a[vt+1]=a[vt];
    }
    a[vt+1]=x;
    n++;
}
void insertionsort (int a[], int n){
    int k=1;
    while (k<=n-1){
        int x=a[k]; int vt=k-1;
        for (;vt>=0&&a[vt]>x; vt--){
            a[vt+1]=a[vt];
        }
        a[vt+1]=x;
        k++;
    }
}
int main(){
    int n=12; int a[20]={2,3,4,5,6,1,0,7,8,9,10,11};
    insertionsort(a,n);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}