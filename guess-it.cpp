#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int GenerateRandomNumber(){
    return rand() %100 +1;
}
int getPlayerGuess(){
    int guess; cin>>guess;
    return guess;
}
int main(){
    srand(time(0));
    int secretNumber=GenerateRandomNumber();
    int guess;
    int count=1;
    do {
        guess=getPlayerGuess();
        system("cls");
        if (guess==secretNumber) {
            cout<<"Correct!\n";
            system("pause");
            break;
        } else{
            if (guess>secretNumber) cout<<left<<setw(40)<<to_string(guess)+" is too big!"<<setw(40)<<count<<endl; else 
                cout<<left<<setw(40)<<to_string(guess)+" is too small!"<<setw(40)<<"count: "+to_string(count)<<endl;
                count++;
            continue;
        } 
    } while (guess!=secretNumber);
    return 0;
}