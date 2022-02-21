#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;
int GCD (int a, int b){
    while (a!=b){
        if (a>b) a=a-b;
        if (b>a) b=b-a;
    }
    return a;
}
float getmax(float a, float b){
    if (a>b) return a; else return b;
}
struct PHANSO{
    int tu;
    int mau;
    bool status_am;
    void Xuat(){
        if (status_am==true) cout<<"-";
        if (mau==1) cout<<tu<<endl; else
        cout<<tu<<"/"<<mau<<endl;
    }
};
//1/2 +2/3
void rutgon(PHANSO &ps){
        int temp=GCD(ps.tu,ps.mau);
        ps.tu=ps.tu/temp;
        ps.mau=ps.mau/temp;
    }
PHANSO operator+ (PHANSO a, PHANSO b){
    PHANSO temp;
    temp.status_am=0;
    temp.mau=a.mau*b.mau;
    temp.tu=a.tu*b.mau+b.tu*a.mau;
    rutgon(temp);
    return temp;
}
PHANSO operator- (PHANSO a, PHANSO b){
    PHANSO temp;
    temp.status_am=0;
    temp.mau=a.mau*b.mau;
    temp.tu=a.tu*b.mau-b.tu*a.mau;
    rutgon(temp);
    return temp;
}
void Doc_1_Phan_So(ifstream &filein, PHANSO &ps){
    string str;
    filein>>str;
    str+='/';
    ps.status_am=false;
    if (str.size()==str.find("/")+1){
        ps.tu=stoi(str.substr(0,str.find("/")));
        if (ps.tu<0){
                ps.tu=-ps.tu;
                ps.status_am=true;
            }
        ps.mau=1;
    } else {
            ps.tu=stoi(str.substr(0,str.find("/")));
            if (ps.tu<0){
                ps.tu=-ps.tu;
                ps.status_am=true;
            }
            ps.mau=stoi(str.substr(str.find("/")+1,str.size()-str.find("/")-2));
            if (ps.mau<0&&ps.status_am==true){
                ps.mau=-ps.mau;
                ps.status_am=false;
            }
            if(ps.mau<0&&ps.status_am==false){
                ps.mau=-ps.mau;
                ps.status_am=true;
            }
    }
    
}
void Doc_1_Danh_Sach(ifstream &filein, vector <PHANSO> &arr){
    string temp;
    while (!filein.eof())
    {
        PHANSO ps;
        Doc_1_Phan_So(filein,ps);
        arr.push_back(ps);
    }
}
int main(){
    vector <PHANSO> arr;
    ifstream filein; filein.open("INPUT.txt", ios_base::in);
    Doc_1_Danh_Sach(filein,arr);
    float temp_max=arr[0].status_am==1?-1.0*(float)arr[0].tu/arr[0].mau: (float)arr[0].tu/arr[0].mau ;
    int index_max=0;
    for (int i=0; i<arr.size();i++){
        rutgon(arr[i]);
        arr[i].Xuat();
        if (arr[i].status_am==1? -1.0*(float)arr[i].tu/arr[i].mau: (float)arr[i].tu/arr[i].mau>temp_max){
            temp_max=arr[i].status_am==1? -1.0*(float)arr[i].tu/arr[i].mau: (float)arr[i].tu/arr[i].mau;
            index_max=i;
        }
    }
    cout<<endl;
    arr[index_max].Xuat();
    cout<<endl;

    return 0;
}