#include <iostream>
using namespace std;
int a[100]; int n; 
void VT_to_N_0(int vt, int a[], int n){
    for (int i=vt; i<n; i++){
        a[i]=0;
    }
}
void khoitao(int *a, int n){
    for (int i=0; i<n; i++){
        a[i]=0;
    }
}
void xuat (int a[], int n){
    for (int i=0; i<n; i++){
        cout<<a[i];
    }
    cout<<endl;
}
void sinhxaunhiphan(int a[],int n){
    xuat(a,n);
    int i=n-1;
    while(i>0){
        if (a[i]==1) i--;
        if (a[i]==0){
            a[i]=1;
            VT_to_N_0(i+1,a,n);
            xuat(a,n);
            i=n-1;  
        }
    }

}
int main(){
    cin>>n;
    khoitao(a,n);
    sinhxaunhiphan(a,n);
    return 0;
}