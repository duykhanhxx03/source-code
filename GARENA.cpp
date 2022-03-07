#include <iostream>
#include <cctype>
#include <string>
bool is_number(char c){
    if (c>='0' && c<='9') return 1; else return 0;}
bool is_alpha(char c){
    if ((c>='A' && c<='Z')||(c>='a'&&c<='z')) return 1; else return 0;}
using namespace std;
int main(){
    string line="";
    cin>>line;
    bool is_true=true;
    if ((line.length()<6)||(line.length()>15)||is_number(line[0])==true) is_true=false;
        else {
            for (int i=0; i<line.length(); i++){
                if (is_number(line[i])==false&&is_alpha(line[i])==false) {
                    is_true=false;
                    break;
                } 
            }
        }
    if (is_true==true) cout<<"Valid username."; else cout<<"Invalid username.";
    return 0;
}