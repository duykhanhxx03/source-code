#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void printArrow(int n, bool left){
    vector <string> vector_temp;
    if(left==false){
        for (int i=0,j=0; i<n; i++, j+=2){
            string temp; temp+=string(j,' ')+string(n-i,'*');
            vector_temp.push_back(temp);
        }
        
    }else {
        for (int i=n; i>=1; i--){
            string temp; temp+=string(i-1,' ')+string(i,'*');
            vector_temp.push_back(temp);
        }
    }
    for (int i=0; i<=n-1; i++) cout<<vector_temp[i]<<endl;
    for (int i=n-2; i>=0; i--) cout<<vector_temp[i]<<endl;
}
int main(){
    int n; cin>>n; 
    printArrow(n,1);
    return 0;
}