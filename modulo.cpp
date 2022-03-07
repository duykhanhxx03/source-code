#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
string pigLatin(string word){
    if (word.size()==0) return "";
    if(word[0]=='u'||word[0]=='e'||word[0]=='o'||word[0]=='a'||word[0]=='i'){
        return word+"way";
    }
    else
        {
            string temp="";
            temp+=word.substr(1,word.size()-1)+word[0]+"ay";
            return temp;
        }    
}
int main ()
{
    string s; cin>>s;
    system("cls");
    cout<<pigLatin(s);
    return 0;
}