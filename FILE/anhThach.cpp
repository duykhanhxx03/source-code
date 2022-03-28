#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int count=0;
    for (int i=1; i<=100; i++){
        if(i%6==0||i%10==0||i%15==0) count++;
    }
    cout<<count;
    return 0;
}