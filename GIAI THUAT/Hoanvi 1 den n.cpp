#include <iostream>
using namespace std;
void sapxepdoixungtang(int a[], int n, int begin){
    for (int i=begin; i<n; i++){
        for (int j=i+1; j<=n; j++){
            if (a[i]>a[j]) swap(a[i],a[j]);
        }
    }
}
void khoitaomang(int a[], int n){
    for (int i=1; i<=n; i++){
        a[i]=i;
    }
}
void xuat(int a[], int n){
    for (int i=1; i<=n; i++){
        cout<<a[i];
    }
    cout<<endl;
}
void hoanvi(int a[], int n){
    khoitaomang(a,n);
    xuat(a,n);
    while (true){
        int i;
        for (i=n; i>0; i--){
            if (i==1) return;
            if (a[i-1]<a[i]) break;
        }
        for (int j=n; j>=i; j--){
            if (a[j]>a[i-1]){
                swap(a[i-1],a[j]);
                sapxepdoixungtang(a,n,i);
                xuat(a,n);
                break;
            }
        }
    }
}
int main(){
    int a[100]; int n; cin>>n;
    hoanvi(a,n);
    return 0;
}