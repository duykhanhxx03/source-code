#include <iostream>
#include <string>
using namespace std;
#include <map>
#include <algorithm>
char secondChar(string s)
{
    sort(s.begin(), s.end());

}
int main(){
    string s="coodddeeee";
    sort(s.begin(), s.end());
    cout<<s;
    //cout<<secondChar(s);
    return 0;
}