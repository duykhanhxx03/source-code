#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream filein;
	filein.open("SINHVIEN.txt", ios_base::in);
    string str;
    getline(filein, str,','); cout<<str<<endl;
    //cout<<filein.tellg();
    filein.seekg(-3,ios_base::cur);
    getline(filein, str, ','); cout<<str<<endl;
    filein.seekg(-3,ios_base::cur);
    getline(filein, str, ','); cout<<str<<endl;
	filein.close();
    return 0;
}