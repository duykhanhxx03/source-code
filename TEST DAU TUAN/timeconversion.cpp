#include <iostream>
#include <string>
using namespace std;
string timeConversion(string s) {
    
}
int main(){
    string str="12:01:00PM";
    int h,m,s; string AM_PM;
    h=stoi(str.substr(0,2));
    m=stoi(str.substr(3,2));
    s=stoi(str.substr(6,2));
    AM_PM=str.substr(8,2);
    
    return 0;
}