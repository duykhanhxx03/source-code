#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream FileIn; FileIn.open("demo_in.txt", ios_base::in);
    ofstream FileOut; FileOut.open("demo_out.txt", ios_base::out);
    string str;
    getline(FileIn,str,',');
    cout<<FileIn.tellg()<<" "<<str<<endl;
    getline(FileIn,str,',');
    cout<<FileIn.tellg()<<" "<<str<<endl;
    getline(FileIn,str,',');
    cout<<FileIn.tellg()<<" "<<str<<endl;
    FileIn.close(); FileOut.close();
    return 0;
}