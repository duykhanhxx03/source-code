#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "wordlist&figure.h"
using namespace std;
struct player{
    string name;
    int score;
    player(){};
    player(string name, int score){
        this->name=name;
        this->score=score;
    }
};
const int MAX_BAD_GUESSES=7;
const int WORD_COUNT=sizeof(WORD_LIST)/sizeof(string);
string chooseWord();
void renderGame (const string &guessedWord,const int &badGuessCount,const player &pl);
void update(string &guessedWord, const string &secretWord, char guess);
bool contains (const string &word,const char &ch);
void gameMain(player &pl);
void createPlayer(vector <player> &LIST_PLAYERS);
void printChart(vector <player> &LIST_PLAYERS);
void preProcess(vector <player> &LIST_PLAYERS);
void getPlayerInfoFromFile(fstream &playerInfo,vector <player> &LIST_PLAYERS);
void sort(vector <player> &LIST_PLAYERS);
int main(){
    vector <player> LIST_PLAYERS;
    fstream playerInfo ("player.info",ios::in|ios::out);
    getPlayerInfoFromFile(playerInfo,LIST_PLAYERS);
    remove("player.info");
    int choose;
    do {
        cout<<string(40,'-')<<endl;
        cout<<"1. PLAY NOW"<<endl
            <<"2. Print chart"<<endl
            <<"3. Create new player"<<endl
            <<"4. Delete a player"<<endl
            <<"0. exit"<<endl;
        cin>>choose;
        switch (choose){
            case 1:
                cout<<"HANGMAN CUSTOM VERSION 2.1 "<<endl;
                preProcess(LIST_PLAYERS);
                break;
            case 2:
                system("cls");
                cout<<"Print chart"<<endl;
                printChart(LIST_PLAYERS);
                break;
            case 3:
                system("cls");
                cout<<"Create new player: "<<endl;
                createPlayer(LIST_PLAYERS);
                break;
            case 4:
                system("cls");
                cout<<"Print chart"<<endl;
                printChart(LIST_PLAYERS);
                int orderNumber;
                cout<<"Enter the order number: "; cin>>orderNumber;
                LIST_PLAYERS.erase(LIST_PLAYERS.begin()+orderNumber-1);// vi so thu tu di tu so mot
                break; 
            case 0:
                cout<<"Exit"<<endl;
                fstream playerInfo ("player.info",ios::in|ios::out);
                for (int i=0; i<LIST_PLAYERS.size(); i++){
                    playerInfo<<LIST_PLAYERS[i].name<<"|"<<LIST_PLAYERS[i].score<<endl;
                }
                break;
        }
    } while (choose!=0);
    playerInfo.close();
    return 0;
}
void sort(vector <player> &LIST_PLAYERS){
    for (int i=0; i<LIST_PLAYERS.size()-1; i++){
        for (int j=i+1; j<LIST_PLAYERS.size(); j++){
            if (LIST_PLAYERS[j].score>LIST_PLAYERS[i].score){
                player temp=LIST_PLAYERS[j];
                LIST_PLAYERS[j]=LIST_PLAYERS[i];
                LIST_PLAYERS[i]=temp;
            }
        }
    }
}
string chooseWord (){
    int randomIndex= rand()%WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void renderGame (const string &guessedWord, const int &badGuessCount, const player &pl){
    cout<<FIGURE[badGuessCount]<<endl;
    cout<<"Live score : "<<pl.score<<endl;
    cout<<guessedWord<<endl;
    cout<<"Number of wrong guesses:"<<badGuessCount<<endl;
}
void update(string &guessedWord,const string &secretWord, char guess){
    for (int i=0; i<secretWord.size(); i++){
        if (guess==secretWord[i]) guessedWord[i]=guess;
    }
}
bool contains (const string &word, const char &ch){
    for (int i=0; i<word.size(); i++){
        if (word[i]==ch) return true;
    }
    return false;
}
void gameMain(player &pl){
    srand(time(0));
    string secretWord=chooseWord();
    char guess;
    guess=tolower(guess);
    int badGuessCount=0;
    string guessedWord=string(secretWord.size(),'-');
    do {
        system("cls");
        renderGame(guessedWord,badGuessCount,pl);
        cin>>guess;
        if (contains(secretWord,guess)==true){
            update(guessedWord,secretWord,guess);
            pl.score++;
        } else {
            badGuessCount++;
        }

    }  while (badGuessCount<MAX_BAD_GUESSES&&secretWord!=guessedWord);
    system("cls");
    renderGame(guessedWord,badGuessCount,pl);
    if (badGuessCount<MAX_BAD_GUESSES) cout<<"Congratulations! You win!"; 
        else cout<<"You lost. The secret word is "<<secretWord<<endl;
}
void createPlayer(vector <player> &LIST_PLAYERS){
    player pl;
    string temp_name;
    bool is_true;
    do {
        cin.ignore();
        is_true=1;
        cout<<"Enter your username: "; getline(cin,temp_name); cout<<endl;
        for (int i=0; i<LIST_PLAYERS.size(); i++){
            if (temp_name==LIST_PLAYERS[i].name) is_true=0;
        }
        if (is_true==0) cout<<"This username already exists! Please try a diffrent name!"<<endl;
    } while(is_true==0);
    pl.name=temp_name;
    pl.score=0;
    LIST_PLAYERS.push_back(pl);
}
void printChart(vector <player> &LIST_PLAYERS){
    if (LIST_PLAYERS.size()==0) cout<<"Chart is empty!"<<endl; 
        else{
            sort(LIST_PLAYERS);
            cout<<string(40,'-')<<endl;
            for (int i=1; i<=LIST_PLAYERS.size(); i++){
                cout<<"|"<<left<<setw(2)<<i<<". "<<left<<setw(20)<<LIST_PLAYERS[i-1].name<<"| "<<"score: "<<LIST_PLAYERS[i-1].score<<right<<setw(5)<<" |"<<endl;
            }
        }
}
void preProcess(vector <player> &LIST_PLAYERS){
    int index;
    
    if (LIST_PLAYERS.size()==0){
        cout<<"Player list is empty! Please create a username:"<<endl;
        createPlayer(LIST_PLAYERS);
        gameMain(LIST_PLAYERS[0]);
    } else {
    cout<<"Please enter your username:"<<endl;
    cin.ignore();
    do {
        string temp_name; getline(cin,temp_name);
        index=-1;
        for (int i=0; i<LIST_PLAYERS.size(); i++){
            if (temp_name==LIST_PLAYERS[i].name){
                index=i;
                break;
            }
        }
        if (index==-1) cout<<"No exist. Check it again!"<<endl; 
    } while (index==-1);
        gameMain(LIST_PLAYERS[index]);
    }
}
void getPlayerInfoFromFile(fstream &playerInfo,vector <player> &LIST_PLAYERS){
    string temp_name=""; int temp_score=0;
    if (playerInfo.eof()) return;
    while(!playerInfo.eof()){
        getline(playerInfo,temp_name,'|');
        if (temp_name=="") break;
        playerInfo>>temp_score;
        playerInfo.ignore();
        LIST_PLAYERS.push_back(player(temp_name,temp_score));
    }
    if (LIST_PLAYERS.size()!=0) sort(LIST_PLAYERS);
}