#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream FileIn; FileIn.open("demo_in.txt", ios::in);
    ofstream FileOut; FileOut.open("demo_out.txt", ios::out);
    int temp;
    FileIn.seekg(3,ios::beg);
    FileIn>>temp;
    cout<<temp;
    FileIn.close(); FileOut.close();
    return 0;
}